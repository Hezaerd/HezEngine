#pragma once

namespace HezEngine
{
	class Timestep
	{
	public:
		Timestep(float pTime = 0.0f)
			: m_Time(pTime)
		{
		}

		operator float() const { return m_Time; }

		float GetSeconds() const { return m_Time; }
		float GetMilliseconds() const { return m_Time * 1000.0f; }

	private:
		float m_Time;
	};
}