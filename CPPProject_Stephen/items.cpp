#include "Item.h"
#include "Inventory.h"

Item::Item() { 
	i_name = "Nothing";
	i_id = 0;
	i_restore = 0;
	i_type = 0;
}

Item::Item(int id) {
	switch (id) {
	case 1:
		i_name = "Potion";
		i_restore = 20;
		i_type = 1;
		break;
	case 2:
		i_name = "Hi-Potion";
		i_restore = 100;
		i_type = 1;
		break;
	}
}