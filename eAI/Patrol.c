#ifndef BAM_PATROL
#define BAM_PATROL

class Patrol {
	private TVectorArray m_waypoints;
	private string m_loadout;
	private int m_bots;
	
	void Patrol(TVectorArray waypoints, string loadout = "HumanLoadout.json", int bots = 2)
	{
		m_waypoints = waypoints;
		m_loadout = loadout;
		m_bots = bots;
	}

	ref TVectorArray getWaypoints()
	{
		return m_waypoints;
	}
	
	string getLoadout()
	{
		return m_loadout;
	}
	
	int getBots()
	{
		return m_bots;
	}
	
	eAIDynamicPatrol getDynamicPatrol()
	{
		return new eAIDynamicPatrol(m_waypoints[0], m_waypoints, m_loadout, m_bots);
	}
}

#endif