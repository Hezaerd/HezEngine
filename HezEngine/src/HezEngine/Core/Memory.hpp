#pragma once

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
	};
}
