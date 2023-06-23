#ifndef BAM_CLOTHING
#define BAM_CLOTHING

class BAM_Clothing {
    string m_top;
    string m_pants;
    string m_shoes;
    string m_backpack;
    string m_helmet;
    string m_hands;

    void BAM_Clothing(string top, string pants, string shoes, string backpack, string helmet, string hands) {
        m_top = top;
        m_pants = pants;
        m_shoes = shoes;
        m_backpack = backpack;
        m_helmet = helmet;
        m_hands = hands;
	}

    void applyTo(PlayerBase player) {
        player.RemoveAllItems();
        addToInventoy(player.GetInventory());
    }

    void addToInventoy(GameInventory inventory) {
        if (m_top) {
            inventory.CreateInInventory(m_top);
        }
        
        if (m_pants) {
            inventory.CreateInInventory(m_pants);
        }
        
        if (m_shoes) {
            inventory.CreateInInventory(m_shoes);
        }
        
        if (m_backpack) {
            inventory.CreateInInventory(m_backpack);
        }
        
        if (m_helmet) {
            inventory.CreateInInventory(m_helmet);
        }
        
        if (m_hands) {
            inventory.CreateInInventory(m_hands);
        }
    }
};

#endif