
//{{BLOCK(menu)

//======================================================================
//
//	menu, 256x256@4, 
//	+ palette 256 entries, not compressed
//	+ 110 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 512 + 3520 + 2048 = 6080
//
//	Time-stamp: 2024-10-12, 00:05:05
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MENU_H
#define GRIT_MENU_H

#define menuTilesLen 3520
extern const unsigned int menuTiles[880];

#define menuMapLen 2048
extern const unsigned short menuMap[1024];

#define menuPalLen 512
extern const unsigned short menuPal[256];

#endif // GRIT_MENU_H

//}}BLOCK(menu)
