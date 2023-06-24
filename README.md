<h1 align="center">
     MINISHELL
</h1>

### İçindekiler

1. [Shell Program Yapıları](#1-shell-program-yapıları)
     1. [Lexer](#11-lexer)
     2. [Parser](#12-parser)
     3. [Executor](#13-executor)
     4. [Pipe](#14-pipe)
     5. [Çıkış Durumu $?](#15-çıkış-durumu)
2. [Çalışma Yapısı](#2-çalışma-yapısı)
     1. [Akış Şeması](#21-akış-şeması)
     2. [Fonksiyonlar](#22-fonksiyonlar)

<br>

## 1. Shell Program Yapıları


### 1.1 Lexer
- Lexer, metin girdisini tararken belirli dilbilgisi kurallarına dayalı olarak metni analiz eder.
- Bash shell için lexer, girilen metni parçalara ayırır ve her parçayı birer "token" olarak tanımlar.
- Tokenler, komutlar, argümanlar, değişkenler, operatörler vb. gibi dilbilgisi yapılarını temsil eder.
- Lexer, metindeki karakterleri okur, bu karakterlerin anlamsal gruplara ayrılmasını sağlar ve daha sonra bu tokenlerin bir listesini oluşturur.

### 1.2 Parser
- Parser, lexer tarafından oluşturulan token listesini alır ve bu tokenlerin belirli bir dilbilgisi yapısını takip ettiğini kontrol eder.
- Parser, dilbilgisi kurallarını kullanarak tokenleri işler, onları sözdizimsel olarak doğru bir şekilde sıralar ve dilin gramerine uygun bir ağaç yapısı oluşturur.
- Bash shell için parser, komutların doğru bir şekilde düzenlenmesini, argümanların ve seçeneklerin doğru yerleştirilmesini ve işaretçilerin (örneğin; ifadelerin bitişini veya döngülerin başlangıcını belirten belirteçler) doğru kullanılmasını kontrol eder.

### 1.3 Executor
- Executor, parser tarafından oluşturulan dilbilgisi ağacını alır ve bu ağaçtaki her komut için bir işlem oluşturur.
- Bash shell için executor, komutları işletmek ve sonuçlarını elde etmekle sorumludur.
- Executor, komutları işletirken, değişkenleri değerlendirir, dosya işlemlerini gerçekleştirir, diğer programları çalıştırır ve gerektiğinde çıktıyı bir sonraki komuta yönlendirmek için boruları (pipe) oluşturur.
- Executor ayrıca koşullu ifadeleri değerlendirir, döngülerin döngü koşullarını kontrol eder ve program akışını yönetir.

### 1.4 Pipe
- Bir işlemin çıktısını doğrudan başka bir işlemin girişine yönlendirmek için kullanılır.
- Birden çok işlemi bir araya getirerek verimli bir şekilde çalışmalarını sağlar.
- Pipe, dikey çubuk " | " sembolü ile temsil edilir.
```
ls | grep ".txt"
```
- Bu komut "ls" komutunun çıktısındaki ".txt" uzantısına sahip olan dosyaları filtrelemek için "grep" komutunu kullanılır.
- "ls" komutu dosya listesini üretir ve bu çıktı "grep" komutuna geçirilir. Sonuç olarak, yalnızca ".txt" uzantısına sahip dosyalar ekrana yazdırılır.

### 1.5 Çıkış Durumu
- Her bir komut çalıştırıldığında, çıkış durumu bir tam sayı değeriyle temsil edilir.
- Başarı durumunda genellikle 0 değeri döndürülür, hata durumunda ise farklı bir değer döndürülür.
- "$?" değişkeni, en son çalıştırılan komutun çıkış durumunu içerir.

## 2. Çalışma Yapısı


### 2.1 Akış Şeması

![image](https://github.com/Yakupacs/Ecole42_Minishell/assets/73075252/95882bea-cef8-4113-9354-8da56ccaaa55)

### 2.2 Fonksiyonlar

| Fonksiyon  | Kütüphane | İşlev |
| ------------- | ------------- | ------------- |
| printf  | <stdio.h>  | Çıktıyı stdout'a yazdırır. |
| malloc  | <stdlib.h>  | Dinamik bellek ayırır. |
| free  | <stdlib.h>  | Dinamik belleği serbest bırakır. |
| read  | <unistd.h>  | Veriyi okur. |
| write  | <unistd.h>  | Veriyi yazar. |
| open  | <fcntl.h>  | Dosyayı açar. |
| close  | <unistd.h>  | Dosyayı kapatır. |
| fork  | <unistd.h>  | Yeni bir child process oluşturur. |
| wait  | <sys/wait.h>  | Bir child process işleminin tamamlanmasını bekler. |
| waitpid  | <sys/wait.h>  | Belirli bir child process işleminin tamamlanmasını bekler. |
| wait3  | <sys/wait.h>  | Bir child process işleminin tamamlanmasını bekler. |
| wait4  | <sys/wait.h>  | Belirli bir child process işleminin tamamlanmasını bekler. |
| signal  | <signal.h>  | Sinyal yakalayıcıyı ayarlar. |
| kill  | <signal.h>  | İşlemi sonlandırıp sinyal gönderir. |
| exit  | <stdlib.h>  | Programda çıkış yapar. |
| getcwd  | <unistd.h>  | Geçerli çalışma dizinini alır. |
| chdir  | <unistd.h>  | Çalışma dizinini değiştirir. |
| stat  | <sys/stat.h>  | Dosya veya dizin hakkında bilgi alır. |
| lstat  | <sys/stat.h>  | Sembolik bağlantının kendisi hakkında bilgi alır. |
| fstat  | <sys/stat.h>  | Dosya tanımlayıcısına bağlı dosya hakkında bilgi alır. |
| execve  | <unistd.h>  | Yeni bir program yürütür. |
| dup  | <unistd.h>  | Dosya tanımlayıcısını kopyalar. |
| dup2  | <unistd.h>  | Dosya tanımlayıcısını belirtilen dosya tanımlayıcısına kopyalar. |
| pipe  | <unistd.h>  | İki yönlü bir iletişim kanalı (pipe) oluşturur. |
| opendir  | <dirent.h>  | Dizin akışını açar. |
| readdir  | <dirent.h>  | Bir sonraki dizin girdisini okur. |
| closedir  | <dirent.h>  | Dizin akışını kapatır. |
| strerror  | <string.h>  | Hata numarasına karşılık gelen bir hata açıklaması döndürür. |
| errno  | <errno.h>  | Hata kodunu tutan bir değişken. |
| termcap  | <term.h>  | Terminal özelliklerini elde eder. |
