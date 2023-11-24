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

# Struktur Program

├── README.md

├── Kamar KAFKA			     # main folder

|   ├─── save		

      ├─── HADS.txt
    
      ├─── config.txt
    
      ├─── pp.txt
    
      ├─── test1.txt
    
      ├─── test2.txt
    
|   ├─── src 	

      ├─── ADT
      
        ├─── Album
        
          ├─── a.out
          
          ├─── album.c
          
          ├─── album.h

          ├─── albumDriver
          
          ├─── albumDriver.c
          
        ├─── globalvar
        
          ├─── globalvar.c
          
          ├─── globalvar.h
          
        ├─── List
        
          ├─── list.c
          
          ├─── list.h

          ├─── listDriver
          
          ├─── listDriver.c
          
        ├─── ListPlaylistDinamis
        
          ├─── listPlaylist.c
          
          ├─── listPlatlist.h

          ├─── listPlaylistDriver.c
          
        ├─── Mesinkarakter
        
          ├─── a.out
          
          ├─── empty.txt
          
          ├─── mesinkarakter.c
          
          ├─── mesinkarakter.h
          
          ├─── mesinkarakterDriver.c
          
          ├─── test.txt
          
        ├─── Mesinkata
        
          ├─── mesinkata.c
          
          ├─── mesinkata.h
          
          ├─── mesinkataDriver.c
          
          ├─── test.txt
         
        ├─── Penyanyi
        
          ├─── Penyanyi.c
          
          ├─── Penyanyi.h

          ├─── PenyanyiDriver
          
          ├─── PenyanyiDriver.c
          
          ├─── a.out
          
        ├─── Playlist
        
          ├─── playlist.c
          
          ├─── playlist.h
          
        ├─── Queue
        
          ├─── queue.c
          
          ├─── queue.h
          
          ├─── queueDriver

          ├─── queueDriver.c
          
          ├─── driverqueue.c
          
        ├─── Stack
        
          ├─── a.out
          
          ├─── stack.c
          
          ├─── stack.h

          ├─── stackDriver
          
          ├─── stackDriver.c
          
        ├─── boolean.h
        
        ├─── func
        
          ├─── a.out
          
          ├─── func.c
          
          ├─── func.h

          ├─── funcDriver
          
          ├─── funcDriver.c
          
      ├─── command
      
        ├─── a.out
        
        ├─── console.c
        
        ├─── console.h
        
   ├─── .gdb_history	

   ├─── main

   ├─── main.bat

   ├─── main.c	     

   ├─── main.sh		

   ├─── peda-session-main.txt

   ├─── welcome.c		

   └─── welcome.h                          



"
## Struktur Program
```
.
├── README.md
├── Kamar KAFKA			     # main folder
      │   ├─── save			    
            │   ├─── HADS.txt 			     
            │   ├─── config.txt		
            │   ├─── DaftarKataHangman.txt	
            │   ├─── DinerDash.txt
            │   ├─── drivermesinkata.txt		     
      │   ├─── hangman.txt		
      │   ├─── save.txt			     
      │   ├─── save2.txt			     
      │   ├─── save3.txt		     
      │   ├─── snakeonmeteor.txt			     
      │   └─── towerofhanoi.txt	                          
│ 
├── source
│   ├─── boolean.h
│   ├─── ADT				     # folder berisikan main
│   │      ├─── array
│   │      │       ├─── arraydin.h
│   │      │       ├─── arraydin.c
│   │      │       ├─── driver_arraydin.c
│   │      │       ├─── arraymap.h
│   │      │       ├─── arraymap.c
│   │      │       └─── driver_arraymap.c
│   │      │
│   │      ├─── map
│   │      │       ├─── map.h
│   │      │       ├─── map.c
│   │      │       └─── driver_map.c
│   │      │
│   │      ├─── mesinkarakter
│   │      │       ├─── mesinkarakter.h
│   │      │       ├─── mesinkarakter.c
│   │      │       └─── driver_mesinkar.c
│   │      │
│   │      ├─── mesinkata
│   │      │       ├─── mesinkata.h
│   │      │       ├─── mesinkata.c
│   │      │       └─── driver_mesinkar.c
│   │      │
│   │      ├─── queue
│   │      │       ├─── queue.h
│   │      │       ├─── queue.c
│   │      │       └─── driver_queue.c
│   │      │
│   │      ├─── queuedinerdash
│   │      │       ├─── queue.h
│   │      │       ├─── queue.c
│   │      │       └─── driver_queue.c
│   │      │
│   │      └─── stack
│   │      │       ├─── stack.h
│   │      │       ├─── stack.c
│   │      │       └─── driver_stack.c
│   │      └─── listdp
│   │              ├─── listdp.h
│   │              ├─── listdp.c
│   │              └─── driver_listdp.c
│   │
│   └─── command
│          ├─── console.h
│          └─── console.c
│
│
└── docs 
     ├─── Spesifikasi Tugas Besar 1 IF2111 2022_2023.docx
     ├─── IF2111_TB1_02_08.pdf
     ├─── Form Asistensi Tugas Besar_TB1_02_08.pdf
     ├─── Spesifikasi Tugas Besar 2 IF2111 2022_2023.docx
     ├─── IF2111_TB2_02_08.pdf
     └─── Form Asistensi Tugas Besar_TB2_02_08.pdf
 ```
"
