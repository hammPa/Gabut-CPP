# Gabut-CPP
Ini Proyek dalam C++ saat saya bosan saja tidak ada kerjaan. Jadi jangan terlalu berharap lebih

# 1. Dynamic Array
Pada folder ini disediakan file header hammdynamicarr.hpp yang didalamnya terdapat struct Array dan juga class DynamicArray. 
Didalam struct Array berisi variabel void pointer untuk menunjuk alamat memori dengan tipe data dinamis dan juga string info untuk mengecek tipe datanya nanti.
Didalam DynamicArray terdapat variabel private index dan juga struct Array dengan ukuran max 100.

Didalamnya terdapat 4 method yaitu :
a. Default Constructor : konstruktor kosong yang tidak melakukan apapun
b. Method void dengan dua parameter, yang pertama untuk menyimpan nilai terbaru dengan tipe dinamis menggunakan template, yang kedua untuk menyimpan sisa inputan yang lain, lalu akan dilakukan looping dengan rekursif untuk memasukkan input dari parameter kostruktor ke dalam variabel dinamis sesuai tipe data inputnya, lalu alamatnya akan ditunjuk oleh void pointer dan ditetapkan nama tipe datanya.
Ini juga bisa digunakan untuk menginputkan 1 data ataupun lebih walau bukan disaat pertama inisialisasi.
c. Constructor yang digunakan untuk input
d. Menampilkandata dalam array void pointer dengan menggunakan parsing dengan tipe data pointer

# 2. Let Keyword
Pada folder ini disediakan file header let.hpp yang di dalamnya terdapat class let yang memiliki fungsi fungsi untuk melakukan assignment ke dalam variabel didalamnya untuk menghasilkan class yang mirip dengan keyword let di JavaScript.
Pertama-tama, didalamnya memiliki variabel private berupa std::variant yang memiliki berbagai tipe data yang diberi nama data, lalu yang kedua adalah variabel private berupa std::vector yang memiliki tipe std::variant dengann berbagai  tipe data berbeda untuk menyimpan data.
Lalu saat assignment bisa menggunakan constructor ataupun overloading operator assignment yang akan memperlakukan nilai value secara berbeda yaitu untuk variabel data dan array.
a. data   : tipe data input akan di deteksi lalu akan di masukkan e dalam variabel bertipe variant sesuai tipe datanya
b. array  : setiapinput dalam array akan dimasukkan kedalam std::initializer_list dan aan di  lakukan proses looping untuk  kemudian dimasukkan ke  dalam variabel  private array bertipe vector sesuai tipe datanya

Untuk proses menampilkan menggunakan overloading operator<< yang akan mengecek 3 kondisi yaitu :
a. jika data berisi           : data akan ditampilkan dengan std::get<Type>(data);
b. jika array berisi          : data akan ditampilkan dengan std::get<Type>(data); dengan menggunakan looping 
c. jika data dan array berisi : pada kasus ini akan ditampilkan data dan nilai dari adta akan dihapus, ini terjadi karena ini akan digunakan dalam menampilkan array berdasarkan index dengan menggunakan konsep overloading operator[]

Pada overloading operator[], akan di ambil nilai array tergantung dari index yang di input, lalu akan di return sebagai data baru bertipe let itu sendiri kepada output sehingga akan mengubah data pada variabel private data dan terjadilah kondisi dimana data dan array keduanya terisi, dikasus ini data akan ditampilkan lalu dihapus lagi agar tidak mengganggu saat nanti array di tampilkan seluruhnya.

Disini juga memiliki overloading operator>> yang berguna untuk mendeteksi input yang dimasukkan lalu akan di return variabel bertipe let yang isinya adalah nilai inputan tadi dengan tipe data yang sesuai.
Disini juga menggunakan method yang namanya mirip seperti vector yaitu push_back dan pop_back untuk mengakses pus_back dan pop_back dari vector dari luar tanpa perlu menuliskan namaObjek.arr.push_back( jadi hanya perlu menuliskan namaObjek.push_back )

Terakhir, di header ini ada fitur untuk membandingkan nilai pada  variabel bertipe let baik  data tunggal maupun array berupa overloading operator== dan overloading operator != dan juga operasi aritmatika dengan menggunakan overloading operator+, operator-, operator*, dan operator/

*ditambahkan fitur baru yaitu forEach yang isinya adalah function, syntaxnya seperti JS yaitu : 
array.forEach([](let data){
  std::cout << data << std::endl;
});

# 3. js_map
Pada folder ini disediakann file header jsmap.hpp yang didalamnya terdapat class array custom dengan tipe data yang harus ditetapkan terlebih dahulu.
Didalamnya terdapat method method yang mengimplementasikan konsep Higher Order Function pada JavaScript, yaitu :
a. foreach : fungsi ini menerima satu parameter berupa function, bisa function biasa atau lambda function, tapi direkomendasikan lambda function yang mereturn output, bisa cout ataupun printf, lalu data akan dieksekusi dengan looping yang setiap looping memeanggil function argumen tadi
b. map     : mirip dengan foreach, tapi setiap looping akan menginput nilai dalam array baru, dan array baru akan dikembalikan pada akhir fungsi.
c. sort    : akan mengurutkan array, bisa descending atau ascending, tergantung isi dari function parameter, detailnya :<br>
    - a - b : ascending<br>
    - b - a : descending<br>

# 4. Array Library in C++
📌 Deskripsi
Array Library ini adalah implementasi array dinamis dalam C++ dengan berbagai fitur tambahan seperti:<br>
Push & Pop Elements<br>
Swap, Find, Delete<br>
Mathematical Operations (min, max, average, median, quartiles<br>
Iterator Support<br>
Functional Operations (filter, forEach, reduce, contains)<br>
Operator Overloading<br>
Memory Management (reallocate)<br>

🛠️ Fitur Utama
Manajemen Memori<br>
push(value1, value2, ...)<br>
pop()<br>
reallocate_with_sum_of_element()<br>

Akses Elemen
arr[index]<br>
arr.at(index)<br>
arr.front()<br>
arr.back()<br>

Manipulasi Data
change(index, value)<br>
delete_at(index)<br>
delete_duplicate()<br>
swap(index1, index2)<br>

Operasi Matematis
max(), min(), average(), median()<br>
quartile1(), quartile2(), quartile3()<br>
mode()<br>

Fungsi Tingkat Lanjut
reduce([](int a, int b){ return a + b; }, 0)<br>
contains(value)<br>
filter([](int data){ return data > 20; }) <br>
forEach([](int data){ std::cout << data * 3 << "\n"; }) <br>

Iterator Support
begin() dan end() untuk iterasi elemen<br>

Operator Overloading
Mendukung operasi ==, !=, *, dan lainnya<br>
