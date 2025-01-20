# MP3 Player

A simple MP3 player application built using the C programming language, GTK for the graphical user interface, and GStreamer for media playback. The application allows users to play, pause, stop, and navigate between songs while displaying the currently playing track.

## Features

- **Play/Pause**: Start or pause the playback of a song.
- **Stop**: Stop the currently playing song.
- **Next/Previous**: Navigate between tracks in the playlist.
- **Track Display**: View the title of the currently playing song.

## Technologies Used

- **C**: Core programming language.
- **GTK**: For creating a user-friendly graphical interface.
- **GStreamer**: For handling media playback and audio processing.

## How to Run

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/mp3-player.git
   cd mp3-player
   ```

2. Install dependencies:
   Ensure you have GTK and GStreamer installed on your system.
   ```bash
   sudo apt-get install libgtk-3-dev gstreamer1.0-tools
   ```

3. Compile the code:
   ```bash
   gcc -o mp3_player mp3_player.c `pkg-config --cflags --libs gtk+-3.0 gstreamer-1.0`
   ```

4. Run the application:
   ```bash
   ./mp3_player
   ```
