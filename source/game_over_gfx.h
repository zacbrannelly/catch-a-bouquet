
//{{BLOCK(game_over)

//======================================================================
//
//	game_over, 256x256@4, 
//	+ palette 14 entries, not compressed
//	+ 100 tiles (t|f|p reduced) not compressed
//	+ regular map (in SBBs), not compressed, 32x32 
//	Total size: 28 + 3200 + 2048 = 5276
//
//	Time-stamp: 2024-11-03, 07:56:58
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_GAME_OVER_H
#define GRIT_GAME_OVER_H

#define game_overTilesLen 3200
extern const unsigned int game_overTiles[800];

#define game_overMapLen 2048
extern const unsigned short game_overMap[1024];

#define game_overPalLen 28
extern const unsigned short game_overPal[14];

#endif // GRIT_GAME_OVER_H

//}}BLOCK(game_over)
