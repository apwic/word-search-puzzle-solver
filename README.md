# Word Search Puzzle Solver CPP
> Tugas Kecil Mata Kuliah IF2211 Strategi Algoritma ITB.

## Table of Contents
* [General Info](#general-information)
* [Technologies Used](#technologies-used)
* [Features](#features)
* [Pembagian Tugas](#pembagian-tugas)
* [Setup](#setup)
* [Usage](#usage)
* [Project Status](#project-status)
* [Room for Improvement](#room-for-improvement)
* [Acknowledgements](#acknowledgements)
* [Contact](#contact)
<!-- * [License](#license) -->


## General Information
Word search puzzle adalah permainan kata dimana pemain harus menemukan beberapa kata
tersembunyi dalam kumpulan huruf acak. Kumpulan huruf tersebut biasa diletakkan pada “papan”
berbentuk segi empat atau dapat disebut juga matriks huruf. Kata-kata pada matriks huruf ini dapat
ditemukan dalam delapan arah yang mungkin, yaitu, vertikal ke atas, vertikal ke bawah, horizontal
ke kanan, horizontal ke kiri, diagonal ke kanan atas, diagonal ke kanan bawah, diagonal ke kiri
atas, dan diagonal ke kiri bawah. Word search puzzle pertama kali dibuat oleh Noeman E. Gibat.
Puzzle ini dipublikasikan dalam the Selenby Digest pada 1 Maret 1968 di Norman, Oklahoma.
Setelah itu word search puzzle mulai terkenal di daerahnya. Kemudian beberapa guru meminta
salinannya untuk digunakan sebagai alat mengajar. Akhirnya permainan itu tersebar setelah
seorang guru mengirimkan salinannya kepada teman-teman di kota lain. Sekarang word search
puzzle bisa ditemukan dengan mudah di koran, majalah, bahkan internet


## Technologies Used
- C++ programming language


## Features
Solver untuk Word Search Puzzle dengan delapan arah.

## Setup
- g++ dibutuhkan untuk melakukan build terhadap program ini.
- Siapkan file txt dengan template sesuai contoh pada folder test. Diharuskan untuk melakukan **enter pada akhir file txt** agar kata terakhir dapat dibaca.

## Usage
Gunakan command prompt/terminal\
Pindahkan direktori ke folder src untuk melakukan build\
`g++ word_puzzle_search.cpp -o ../bin/word_puzzle_search.exe`\
Command ini akan secara otomatis melakukan compile terhadap semua file yang dibutuhkan\
Untuk menjalankan program, pindahkan folder ke direktori bin\
`word_puzzle_search.exe`\
Program sudah di-_built_ dan bisa langsung dijalankan dengan command tersebut

## Project Status
Project ini sudah  _selesai_ 

## Room for Improvement
Room for improvement:
- Program ini hanya menggunakan _command line_ sehingga bisa dilakukan visualisasi yang lebih menarik
- Sebagian dari source code yang ditulis itu _redundant_, sehingga bisa dilakukan pengecekan dan penghapusan terhadap beberapa code
- Projek ini terbatas deadline, sehingga code secara keseluruhan agak berantakan dan dapat dikembangkan lebih rapih lagi

## Acknowledgements
- Projek ini dikerjakan untuk memenuhi tugas besar mata kuliah IF2211 Strategi Algoritma
- Terima kasih kepada seluruh dosen pengajar mata kuliah IF2211 Strategi Algoritma

## Contact
Created by:
- [@apwic](https://github.com/apwic)
<!-- Optional -->
<!-- ## License -->
<!-- This project is open source and available under the [... License](). -->

<!-- You don't have to include all sections - just the one's relevant to your project -->
