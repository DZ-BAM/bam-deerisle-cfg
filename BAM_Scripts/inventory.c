#ifndef BAM_INVENTORY
#define BAM_INVENTORY

class BAM_Inventory {
    array<string> m_items;
    array<array<string>> m_random_items;

    void BAM_Inventory(array<string> items, array<array<string>> m_random_items) {
        m_items = items;
        m_random_items = m_random_items;
	}

    void addToPlayer(PlayerBase player) {
        addToInventory(player.GetInventory());
    }

    void addToInventory(GameInventory inventory) {
        if (m_items) {
            foreach (auto item: m_items) {
                inventory.CreateInInventory(item);
            }
        }

        if (m_random_items) {
            foreach (auto selection: m_random_items) {
                inventory.CreateInInventory(selection.GetRandomElement());
            }
        }
    }
};

#endif