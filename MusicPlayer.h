struct Button {
    int x;
    int y;
    int width;
    int height;
    const char *text;
    Color textColor;
    bool isPressed;

};

struct songData {
    const char *songName;
    const char *artistName;
    const char *albumName;
    const char *albumArtDir;
    int year;
};
// Prototypes
void drawAlbumArt(Texture2D albumArt);
void drawBottomBar();
void addButton(struct Button button);
void checkMouseClick();
struct songData createSong(const char *songName, const char *artistName, const char *albumName, const char *albumArtDir, int year);