#pragma once

#include <map>
#include <mutex>

namespace HezEngine
{
	struct AllocationMetrics
	{
		size_t TotalAllocated = 0;
		size_t TotalFreed = 0;
	};

	struct Allocation
	{
		void* Memory = 0;
		size_t Size = 0;
		const char* Tag = 0;
	};

	namespace Memory
	{
		const AllocationMetrics& GetMetrics();
	}

	template <class T>
	struct Mallocator
	{
		typedef T value_type;

		Mallocator() = default;
		template<class U> constexpr Mallocator(const Mallocator<U>&) noexcept {}

		T* allocate(size_t n)
		{
			if (n > std::numeric_limits<size_t>::max() / sizeof(T))
				throw std::bad_array_new_length();

			if (auto p = static_cast<T*>(std::malloc(n * sizeof(T))))
				return p;

			throw std::bad_alloc();
		}

		void deallocate(T* p, size_t) noexcept
		{
			std::free(p);
		}
	};

	struct AllocatorData
	{
		using MapAlloc = Mallocator<std::pair<const void* const, Allocation>>;
		using MetricsMapAlloc = Mallocator<std::pair<const char* const, AllocationMetrics>>;

		using AllocMetricsMap = std::map<const char*, AllocationMetrics, std::less<const char*>, MetricsMapAlloc>;

		std::map<const void*, Allocation, std::less<const void*>, MapAlloc> m_AllocationMap;
		AllocMetricsMap m_AllocationMetricsMap;

		std::mutex m_Mutex, m_MetricsMutex;
	};

	class Allocator
	{
	public:
		static void Init();
		static void Shutdown();

		static void* AllocateRaw(size_t pSize);

		static void* Allocate(size_t pSize);
		static void* Allocate(size_t pSize, const char* pTag);
		static void* Allocate(size_t pSize, const char* pFile, uint32_t pLine);

		static void Free(void* pMemory);

		static const AllocatorData::AllocMetricsMap& GetMetrics() { return s_Data->m_AllocationMetricsMap; }

	private:
		inline static AllocatorData* s_Data = nullptr;
	};
}
