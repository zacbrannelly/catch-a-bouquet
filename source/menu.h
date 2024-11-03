
//{{BLOCK(menu)

//======================================================================
//
//	menu, 256x256@4, 
//	+ palette 13 entries, not compressed
//	+ 125 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 26 + 4000 + 2048 = 6074
//
//	Time-stamp: 2024-11-03, 07:56:58
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MENU_H
#define GRIT_MENU_H

#define menuTilesLen 4000
extern const unsigned int menuTiles[1000];

#define menuMapLen 2048
extern const unsigned short menuMap[1024];

#define menuPalLen 26
extern const unsigned short menuPal[14];

#endif // GRIT_MENU_H

//}}BLOCK(menu)
