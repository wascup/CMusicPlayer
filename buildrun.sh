# gcc MusicPlayer.c -o MusicPlayer -lraylib 

if gcc MusicPlayer.c -O -o MusicPlayer -lraylib; then 
./MusicPlayer;
else 
echo "Failed"; 
fi
