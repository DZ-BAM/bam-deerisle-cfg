ref array<ref Patrol> PATROLS = {
	new Patrol({"3161.399170 22.615067 4068.234863", "3125.670166 22.462461 4063.274414"}),
};

autoptr array<autoptr eAIDynamicPatrol> EAI_DYNAMIC_PATROLS = {};

void InitDynamicPatrols() {
	for (int i = 0; i < PATROLS.Count(); i++) {
		autoptr eAIDynamicPatrol patrol = PATROLS[i].getDynamicPatrol();
		EAI_DYNAMIC_PATROLS.Insert(patrol);
		patrol.UpdateTriggers();
	}
}