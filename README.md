# Tubes-Alstrukdat-IF2111
Notes : untuk history commit Harry buat fungsi play dan save ada di branch Harry karena kemarin pas mau dimerge conflict.

# Dibuat oleh Kelompok 08 K01

18222059	Eleanor Cordelia

18222095	Wisyendra Lunarmalam

18222081	Harry Truman Suhalim

18222099	Dahayu Ramania Aurasindu

18222071 	Richie Leonardo

# Deskripsi Singkat Laporan

WayangWave adalah sebuah aplikasi pemutaran musik yang dimiliki oleh Bandung Bondowoso. Ia ingin meluluhkan hati Roro yang awalnya hanya menyukai lagu hip-hop. Hingga suatu hari ketika Roro sedang tertidur, seluruh teman kasat matanya mendukung Bondowoso dan ingin membuatkannya sebuah aplikasi WayangWave untuk berhasil meluluhkan hati Roro. Kami sebagai kumpulan makhluk kasat mata harus membuat aplikasi WayangWave, sebuah aplikasi pemutar lagu berbasis CLI (command-line interface) dan memberikannya pada Bondowoso. WayangWave ini dibuat dalam bahasa C dengan menggunakan struktur data yang sudah kami pelajari di mata kuliah IF2111 ini.

# Cara Kompilasi Program
gcc "main.c" "welcome.c" "src/ADT/Playlist/playlist.c" "src/ADT/globalvar/globalvar.c" "src/ADT/func/func.c" "src/ADT/ListPlaylistDinamis/listPlaylist.c" "src/ADT/List/list.c" "src/ADT/Mesinkata/mesinkata.c" "src/ADT/Mesinkarakter/mesinkarakter.c" "src/ADT/Queue/queue.c" "src/ADT/Stack/stack.c" "src/command/console.c" -g -o main

./main

# Configuration File yang Tersedia
save/config.txt

# Save File yang Tersedia
save/HADS.txt

save/pp.txt

save/test1.txt

save/test2.txt

## Struktur Program
```
"
├── README.md
├── Kamar KAFKA			     # main folder
|      ├─── save			    
|      │   ├─── HADS.txt 			     
|      │   ├─── config.txt		
|      │   ├─── test1.txt	
|      │   └─── test2.txt
|      ├─── src
|      |   ├─── ADT
|      |      │   ├─── Album		     
|      |      |      │   ├─── a.out	
|      |      |      │   ├─── album.c		     
|      |      |      │   ├─── album.h			     
|      |      |      │   ├─── albumDriver	     
|      |      |      │   └─── albumDriver.c		     
|      |      │   ├─── globalvar
|      |      |      │   ├─── globalvar.c
|      |      |      │   └─── globalvar.h                       
|      |      │   ├─── List
|      |      |      │   ├─── list.c
|      |      |      │   ├─── list.h		     
|      |      |      │   ├─── listDriver			     
|      |      |      │   ├─── listDriver.c	 	     
|      |      │   ├─── ListPlaylistDinamis
|      |      |      │   ├─── listPlaylist.c		     
|      |      |      │   ├─── listPlaylist.h			     
|      |      |      │   └─── listPlaylistDriver.c		
|      |      │   ├─── Mesinkaraker
|      |      |      │   ├─── a.out	
|      |      |      │   ├─── mt.txt		     
|      |      |      │   ├─── mesinkaraker.h			     
|      |      |      │   ├─── mesinkaraker.c    
|      |      |      │   ├─── mesinkarakerDriver.c
|      |      |      │   └─── test.txt		     
|      |      │   ├─── Mesinkata		     
|      |      |      │   ├─── mesinkata.h			     
|      |      |      │   ├─── mesinkata.c
|      |      |      │   ├─── mesinkataDriver.c
|      |      |      │   └─── test.txt			     
|      |      │   ├─── Penyanyi
|      |      |      │   ├─── Penyanyi.h
|      |      |      │   ├─── Penyanyi.c		     
|      |      |      │   ├─── PenyanyiDriver			     
|      |      |      │   ├─── PenyanyiDriver.c
|      |      |      │   └─── a.out		     
|      |      │   ├─── Playlist
|      |      |      │   ├─── playlist.h
|      |      |      │   ├─── playlist.c
|      |      |      │   └─── playlistDriver.c
|      |      │   ├─── Queue	     
|      |      |      │   ├─── a.out	
|      |      |      │   ├─── queue.h		     
|      |      |      │   ├─── queue.c			     
|      |      |      │   ├─── queueDriver     
|      |      |      │   └─── queueDriver.c   
|      |      │   ├─── Stack     
|      |      |      │   ├─── a.out	
|      |      |      │   ├─── stack.h		     
|      |      |      │   ├─── stack.c			     
|      |      |      │   ├─── stackDriver     
|      |      |      │   └─── stackDriver.c 
|      |      │   ├─── boolean.h
|      |      │   └─── func                    
|      |      |      │   ├─── a.out	
|      |      |      │   ├─── func.h		     
|      |      |      │   ├─── func.c			     
|      |      |      │   ├─── funcDriver     
|      |      |      │   └─── funcDriver.c 
|      |   ├─── command                        #additional function
|      |      │   ├─── a.out
|      |      │   ├─── console.h
|      |      │   └─── console.c
|      ├─── docs
|      │   ├─── Spesifikasi Tugas Besar IF2111 2023_2024.pdf		
|      │   ├─── Form Asistensi Tugas Besar_TB_01_08.pdf
|      │   └─── IF2111_TB_01_08.pdf
├── .gdb_history
├── main
├── main.bat
├── main.c
├── main.sh
├── peda-session-main.txt
├── welcome.c
└─── welcome.h
"
