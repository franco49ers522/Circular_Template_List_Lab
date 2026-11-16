# Circular Template List Lab
Jareth Franco | CSCI 272

A console playlist built from Professor Vaughn's starter project. Open the CMake project in CLion, or build it from the project folder:

```sh
g++ -std=c++20 main.cpp LinkedList.cpp Media.cpp Song.cpp Podcast.cpp -o playlist
```

Run `./playlist` (Windows: `.\playlist.exe`) to add songs and podcasts. Option 3 lists every item once, option 4 plays the current item, and option 6 moves to the next one. After the last item, playback returns to the first.

Run with `--songs` for a short song-only demo. It plays Queen, Led Zeppelin, and then Queen again.
