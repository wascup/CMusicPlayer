#include <raylib.h>
#include "MusicPlayer.h"
#include <stdio.h>

const char *ProgramName = "C Music Player";
const int mainProgramFPS = 30;
const int screenWidth = 800;
const int screenHeight = 600;
const int bottomBarWidth = 200;
const int bottomBarHeight = 100;
const Color bgColor = {12,12,12,255};
const Color fgBGColor = {18,18,18,255};
const Color listColor = {28,28,28,255};




int main() {

    InitWindow(screenWidth, screenHeight, ProgramName);
    SetTargetFPS(mainProgramFPS);

    songData wonder = createSong("I Wonder", "Kanye West", "Graduation","resources/Temp.png", 2007);
    songData everywhere = createSong("Everywhere (12\" version)", "Fleetwood Mac", "Tango In The Night","resources/Temp.png", 1990);
    songData closeToYou = createSong("Close To You", "Dayglow", "Harmony House","resources/Temp.png", 2021);
    songData songList[] = {wonder, everywhere, closeToYou};


    
    // TESTING
    Image albumImage = LoadImage(wonder.albumArtDir);
    Texture2D albumArtTexture = LoadTextureFromImage(albumImage);

    //main loop
    while (!WindowShouldClose()) {
        //Check for Inputs
        //checkMouseClick();
        
        BeginDrawing();
        ClearBackground(bgColor);
        
        drawBottomBar();
        drawDummySlider(15);
        drawAlbumArt(albumArtTexture);
        drawSongInfo(wonder);
        drawSongList(songList);

        EndDrawing();
    }


    //Cleanup Crew
    UnloadImage(albumImage);
    UnloadTexture(albumArtTexture);
    CloseWindow();
    return 0;
}


void drawAlbumArt(Texture2D albumArt) {
    DrawTexture(albumArt, 15, 15, WHITE);
}

//Draws the bottom bar
void drawBottomBar() {
    DrawRectangle(0,screenHeight - bottomBarHeight, screenWidth, bottomBarHeight, fgBGColor);
}

//Draws the song info
void drawSongInfo(struct songData song) {
    DrawText(song.songName, 15, 330, 20, RED);
    DrawText(song.artistName, 15, 360, 20, GREEN);
    DrawText(song.albumName, 15, 390, 20, BLUE);
    DrawText(TextFormat("%i", song.year), 15, 420, 20, WHITE);
}

//Draws the BG song list
void drawSongList(struct songData *songList) {
    DrawText("Playlist", 330, 15, 20, WHITE);
    DrawRectangle(330, 40, 460, screenHeight - bottomBarHeight - 75, listColor);

    //Add Song Button
    DrawText("+", screenWidth - 25, screenHeight - bottomBarHeight - 30, 20, WHITE);
    
}


//Draws a temporary fake slider till I add the real one
void drawDummySlider(int headPosition) {
    DrawCircle(15 + headPosition, screenHeight - bottomBarHeight / 2 - 30, 10, WHITE);
    DrawRectangle(15, screenHeight - bottomBarHeight / 2 - 30, screenWidth - 15 - 20, 2, WHITE);
}

//TEMP
void addButton(struct Button button) {
    DrawText(button.text, button.x + 10, button.y + 10, 20, button.textColor);
}

// void checkMouseClick() {
//     if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
//         Vector2 mousePos = GetMousePosition();
//         if (mousePos.x > 10 && mousePos.x < 60 && mousePos.y > 50 && mousePos.y < 100) {
//             //play music
//             printf("Play button clicked\n");
//         }

//     }
// }

//Creates a new song struct
songData createSong(const char *songName, const char *artistName, const char *albumName, const char *albumArtDir, int year) {
    songData newSong;
    newSong.songName = songName;
    newSong.artistName = artistName;
    newSong.albumName = albumName;
    newSong.year = year;
    newSong.albumArtDir = albumArtDir;
    return newSong;
}
