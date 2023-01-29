ref array<ref Patrol> PATROLS = {
	new Patrol({"3161.399170 22.615067 4068.234863", "3125.670166 22.462461 4063.274414", "3077.032471 22.462492 3950.293457", "3005.885498 22.462496 3977.589355", "2816.327637 22.450005 3702.208740", "2794.240967 22.585320 3596.804688", "2845.556885 22.462494 3549.835449", "2930.342041 22.462500 3642.004639", "3029.656494 22.462500 3546.509033", "2952.529541 22.462496 3447.867188", "2757.197266 22.612377 3568.838623", "2707.633301 22.562475 3578.896484", "2483.411621 35.112488 3356.334961"}), //paris
	new Patrol({"7278.822754 60.411369 3512.452148", "7154.507813 50.176540 3923.657715", "6936.940918 47.919800 3935.347168", "6829.193848 10.124704 4380.458984", "6721.030273 66.413155 5465.602051", "6885.098145 16.543583 4639.986816", "6998.763672 23.766727 4767.001953"}), //tradersüdnord
	new Patrol({"6616.108887 37.675190 4077.521240", "6708.014648 41.671158 4030.469727", "6889.029297 43.832188 4006.639648", "7100.065391 23.738096 4172.938965", "7275.710449 31.498491 4015.638184", "7412.480957 27.662294 3966.837646", "7360.773438 33.431770 3781.454834", "7175.538574 45.156956 3511.492676"}), //tradernordsüd
	new Patrol({"5872.669922 74.000000 3737.080078", "5144.982422 74.012505 3178.876221", "5068.351563 77.098534 3481.319336", "5139.523926 74.012502 3544.065674", "5222.523962 74.012505 3747.120850", "5451.453125 74.631073 3609.703369"}), //airfield
	new Patrol({"3808.982422 20.477251 5628.560547", "4104.060059 20.430000 5799.379883"}), //bahnsüd
	new Patrol({"7186.006836 574.587952 11549.01660"}), //KMUC Prison 01
	//new Patrol({"7146.048340 567.388428 11608.483398"}), //KMUC Prison 02
	//new Patrol({"7166.415039 563.799622 11632.727539"}), //KMUC Prison 03
	//new Patrol({"7159.6875 552.6249 11595.3222"}), //KMUC Prison 04
	//new Patrol({"7179.2324 527.1196 11666.8642"}), //KMUC MidLevel01
	//new Patrol({"7162.1127 522.0944 11682.6308"}), //KMUC MidLevel02
	//new Patrol({"7160.9536 537.7292 11589.1523"}), //KMUC MidLevel03
	};

autoptr array<autoptr eAIDynamicPatrol> EAI_DYNAMIC_PATROLS = {};

void InitDynamicPatrols() {
	for (int i = 0; i < PATROLS.Count(); i++) {
		autoptr eAIDynamicPatrol patrol = PATROLS[i].getDynamicPatrol();
		EAI_DYNAMIC_PATROLS.Insert(patrol);
		patrol.UpdateTriggers();
	}
}