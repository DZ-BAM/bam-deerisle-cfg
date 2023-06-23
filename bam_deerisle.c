void BAM_SetStartingEquipment(PlayerBase player) {
	BAM_SetRandomlyWornRags(player, 4);
	BAM_SetRandomChemlight(player);
	BAM_SetRandomFruit(player);
	BAM_SetClothing(player);
}

void BAM_SetRandomlyWornRags(PlayerBase player, int amount) {
	EntityAI body = player.FindAttachmentBySlotName("Body");

	if (body) {
		EntityAI ragEntity = body.GetInventory().CreateInInventory("Rag");
		ItemBase ragItem;

		if (Class.CastTo(ragItem, ragEntity)) {
			ragItem.SetQuantity(amount);
		}

		BAM_SetRandomHealth(ragEntity);
	}
}

void BAM_SetRandomChemlight(PlayerBase player) {
	string chemlightArray[] = {"Chemlight_White", "Chemlight_Yellow", "Chemlight_Green", "Chemlight_Red"};
	int rndIndex = Math.RandomInt(0, 4);
	EntityAI body = player.FindAttachmentBySlotName("Body");

	if (body) {
		EntityAI chemlight = body.GetInventory().CreateInInventory(chemlightArray[rndIndex]);
		BAM_SetRandomHealth(chemlight);
	}
}

void BAM_SetRandomFruit(PlayerBase player) {
	EntityAI itemEnt;
	float rand = Math.RandomFloatInclusive(0.0, 1.0);

	if (rand < 0.35) {
		itemEnt = player.GetInventory().CreateInInventory("Apple");
	} else if (rand > 0.65) {
		itemEnt = player.GetInventory().CreateInInventory("Pear");
	} else {
		itemEnt = player.GetInventory().CreateInInventory("Plum");
	}

	BAM_SetRandomHealth(itemEnt);
}

void BAM_SetClothing(PlayerBase player) {
	EntityAI feet = player.FindAttachmentBySlotName("Feet");
	
	if (feet) {
		feet.GetInventory().CreateInInventory("jmc_Military_mountain_boots_black");
	}
}

void BAM_SetRandomHealth(EntityAI itemEnt) {
	float randomHealth = Math.RandomFloat(0.45, 0.65);

	if (itemEnt) {
		itemEnt.SetHealth01("", "", randomHealth);
	}
}