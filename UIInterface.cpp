#include "UIInterface.h"


UIInterface::UIInterface(void)
{
}


UIInterface::~UIInterface(void)
{
}

//======================================================
// Inventory functions
//======================================================

void UIInterface::Inventory_Build(std::wstring slotBackground, DWORD inventoryBackground, signed int maxSlots, int slotSize, int rowSize, int gapSize, int posX, int posY)
{
  m_Inventory.setProperty(slotBackground, inventoryBackground, maxSlots, slotSize, rowSize, gapSize, posX, posY);
}

void UIInterface::Inventory_Build(std::wstring slotBackground, std::wstring inventoryBackground, signed int maxSlots, int slotSize, int rowSize, int gapSize, int posX, int posY)
{
  m_Inventory.setProperty(slotBackground, inventoryBackground, maxSlots, slotSize, rowSize, gapSize, posX, posY);
}

void UIInterface::Inventory_CreateIcon(std::wstring iconImage, int iconID)
{
  m_Inventory.newIcon(iconImage, iconID);
}

void UIInterface::Inventory_AddItem(std::wstring itemName, int iconID)
{
  m_Inventory.newItem(itemName, iconID);
}

void UIInterface::Inventory_AddItem(std::wstring itemName, int iconID, signed int itemLocation, int itemID)
{
  m_Inventory.newItem(itemName, iconID, itemLocation, itemID);
}

void UIInterface::Inventory_RemoveItem(signed int itemLocation)
{
  m_Inventory.removeItem(itemLocation);
}

void UIInterface::Inventory_RemoveItem(std::wstring itemName)
{
  m_Inventory.removeItem(itemName);
}

void UIInterface::Inventory_SwapSlots(signed int itemLocation1, signed int itemLocation2)
{
  m_Inventory.swapItem(itemLocation1, itemLocation2);
}

void UIInterface::Inventory_Draw()
{
  m_Inventory.drawElement();
}


//======================================================
// HUD functions
//======================================================

void UIInterface::drawStatusBar(std::wstring, int, int, int, float, float, SpriteStrip)
{

}

void UIInterface::drawStatusIcon(std::wstring, int, int, int, SpriteStrip)
{

}

void UIInterface::drawTextBox(std::wstring, int, int, DWORD, std::wstring)
{

}



//======================================================
// Control functions
//======================================================
void UIInterface::keyPress()
{

}




//======================================================
// Menu functions
//================
