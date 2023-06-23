#ifndef BAM_SPAWN
#define BAM_SPAWN

#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/clothing.c"
#include "$CurrentDir:bam-deerisle-cfg/BAM_Scripts/inventory.c"

const ref BAM_Clothing CLOTHING = new BAM_Clothing(
	"ChernarusSportShirt",
	"SlacksPants_Beige",
	"jmc_Military_mountain_boots_black",
	"",
	"",
	"",
);
const ref BAM_Inventory INVENTORY = new BAM_Inventory(
	{"CombatKnife"},
	{
		{
			"Chemlight_White",
			"Chemlight_Yellow",
			"Chemlight_Green",
			"Chemlight_Red",
		},
		{"Apple", "Pear", "Plum"},
	},
	BAM_quantizedItems(),
	{
		new BAM_Weapon(
			"M4A1",
			{
				"M4_OEBttstck",
				"M4_RISHndgrd",
				"UniversalLight",
				"M4_Suppressor",
				"M4_T3NRDSOptic",
				"Battery9V",
				"Battery9V",
			},
			new BAM_Magazine(
				"Mag_STANAGCoupled_30Rnd",
				WeaponWithAmmoFlags.CHAMBER,
			),
		),
		new BAM_Weapon(
			"Glock19",
			{
				"PistolSuppressor",
				"FNP45_MRDSOptic",
				"TLRLight",
				"Battery9V",
				"Battery9V",
			},
			new BAM_Magazine(
				"Mag_Glock_15Rnd",
				WeaponWithAmmoFlags.CHAMBER,
			),
		),
	},
);

ref map<string, int> BAM_quantizedItems() {
	auto items = new map<string, int>();
	items["Rag"] = 4;
	return items;
}

void BAM_SetStartingEquipment(PlayerBase player) {
	CLOTHING.applyToPlayer(player);
	INVENTORY.addToPlayer(player);
}

#endif