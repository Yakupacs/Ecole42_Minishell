<h1 align="center">
     MINISHELL
</h1>

### İçindekiler

1. [Shell Program Yapıları](#1-shell-program-yapıları)
     1. [Lexer](#11-lexer)
     2. [Parser](#12-parser)
     3. [Executor](#13-executor)
     4. [Pipe](#14-pipe)
     5. [Çıkış Durumu ($?)](#15-çıkış-durumu)
     6. [PID](#16-pid)
     7. [Environments (ENV)](#17-env)
     8. [Export](#18-export)
     9. [Declare](#19-declare)
2. [Çalışma Yapısı](#2-çalışma-yapısı)
     1. [Akış Şeması](#21-akış-şeması)
     2. [Fonksiyonlar](#22-fonksiyonlar)
3. [Redirections - Yönlendirmeler](#3-redirections)
     1. [Giriş Yönlendirme '<'](#31-giriş-yönlendirme)
     2. [Çıkış Yönlendirme '>'](#32-çıkış-yönlendirme)

<br>

## 1. Shell Program Yapıları


### 1.1 Lexer
- Lexer, metin girdisini tararken belirli dilbilgisi kurallarına dayalı olarak metni analiz eder.
- Bash shell için lexer, girilen metni parçalara ayırır ve her parçayı birer **"token"** olarak tanımlar.
- Tokenler, komutlar, argümanlar, değişkenler, operatörler vb. gibi dilbilgisi yapılarını temsil eder.
- Lexer, metindeki karakterleri okur, bu karakterlerin anlamsal gruplara ayrılmasını sağlar ve daha sonra bu tokenlerin bir listesini oluşturur.
```
3 + 4 * 2
```
- Lexer, yukarıdaki örnekte her bir karakteri sırayla analiz eder ve sırasıyla "3", "+", "4", "*" ve "2" karakterlerini analiz edecektir.
- Lexer, karakter analizi sırasında dilbilgisel yapıları (tokenleri) tanır ve oluşturur.
- Tamsayı: "3", "4", "2"
- Operatör: "+", "*"
- Lexer tanımlanan tokenleri çıktı olarak sunar.

*INTEGER: "3"*

*OPERATOR: "+"*

*INTEGER: "4"*

OPERATOR: "*"
 
*INTEGER: "2"*

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
- Pipe, dikey çubuk '|' sembolü ile temsil edilir.
```
ls | grep ".txt"
```
- Bu komut "ls" komutunun çıktısındaki ".txt" uzantısına sahip olan dosyaları filtrelemek için "grep" komutunu kullanılır.
- "ls" komutu dosya listesini üretir ve bu çıktı "grep" komutuna geçirilir. Sonuç olarak, yalnızca ".txt" uzantısına sahip dosyalar ekrana yazdırılır.

### 1.5 Çıkış Durumu
- Her bir komut çalıştırıldığında, çıkış durumu bir tam sayı değeriyle temsil edilir.
- Başarı durumunda genellikle 0 değeri döndürülür, hata durumunda ise farklı bir değer döndürülür.
- "$?" değişkeni, en son çalıştırılan komutun çıkış durumunu içerir.

### 1.6 Pid
- PID, çalışan bir işlemin **benzersiz kimliğini** temsil eder.
- Her işlem, işletim sistemi tarafından PID ile tanımlanan benzersiz bir numaraya sahiptir.
- PID, bir işlemin kimliğini takip etmek, işlemler arasında iletişim kurmak veya işlemi kontrol etmek için kullanılabilir.
```
pid_t pid = getpid();
```
- Bir işlemi sonlandırmak veya durdurmak istediğinizde PID'ye ihtiyaç duyarsınız. Ayrıca belirli bir işlemi izlemek veya diğer işlemlerle etkileşime geçmek için PID kullanabilirsiniz.
- Bir işlem başlamadıysa "pid" numarasının değeri "-1" olarak ayarlanır.

### 1.7 ENV
- Environment variables (Çevresel Değişkenler) sistemdeki programlar ve işlemler tarafından kullanılan değerlerdir.
- Bu değişkenler, çalışan programlara ve komutlara bazı bilgiler sağlamak için kullanılır.
- Bash, bu değişkenlere erişim sağlamak için çeşitli yöntemler sunar.
- Environment variables, **anahtar-değer (key-value)** çiftleridir.
- Anahtarlar değişkenlere erişmek için kullanılan isimlerdir ve değerler ise bu değişkenlerin taşıdığı bilgidir.
- Örneğin, bir "PATH" değişkeni, sistemdeki programların bulunduğu dizinlerin bir listesini içerebilir.
- Bir değişken tanımlamak için:
```
export MY_VARIABLE="Hello, World"
```
değişkenin adını belirtip buna bir değer atamanız gerekir. Bash'te bu işlem için genellikle 'export' komutu kullanılır.
- Bir değişkene erişmek için:
```
echo $MY_VARIABLE
```
**'$'** işaretini kullanarak değişken adını çağırabiliriz.
- Bir değişkeni silmek için:
```
unset MY_VARIABLE
```
- Bazı environment variables, sistem tarafından otomatik olarak tanımlanır ve kullanılabilir. Örneğin:
     - **'PATH'**: Sistemdeki programların bulunduğu dizinlerin listesi
     - **'HOME'**: Kullanıcının ana dizini
     - **'USER'**: Kullanıcının adı
- Bash, çeşitli öntanımlı environment variables sağlar. Örneğin:
     - **'PWD'**: Geçerli çalışma dizini
     - **'SHELL'**: Kullanılan kabul (shell) programının adı
     - **'LANG'**: Dil ayarı

### 1.8 Export
```
export
```
- **"export"** komutu, bir değişkeni kabuk ortamına (environment) aktarmak için kullanılır.
- Bir değişkeni **"export"** ettiğinizde, bu değişken ve değeri, alt kabuk süreçlerine aktarılır ve bu süreçlerde erişilebilir hale gelir.
- "export" komutu, genellikle çevre değişkenlerini (örneğin, PATH, HOME) veya kullanıcı tanımlı değişkenleri alt kabuk süreçlerinde kullanılabilir hale getirmek için kullanılır.
- Aktarılan değişkenler, alt kabuk süreçlerinde değiştirilebilir ve bu değişiklikler ebeveyn kabuk sürecini etkilemez. Yani, alt kabuk süreçlerinde yapılan değişiklikler yalnızca o süreçleri etkiler.
```
my_var="Hello"
export my_var
```
- Yukarıdaki örnekte, "my_var" adında bir değişken oluşturulur ve daha sonra "export" komutuyla kabuk ortamına aktarılır. Bu "my_var" değişkeninin alt kabuk süreçlerinde de erişilebilir hale gelmesini sağlar.

### 1.9 Declare
- **"declare"** komutu, değişkenlerin tanımlanması, türü belirlenmesi ve özelliklerinin atanması için kullanılır.
```
declare [options] variable=value
```
- Değişkenlerin türünü belirleyebilirsiniz. Örneğin, **"-i"** seçeneğiyle bir değişkeni tamsayı (integer) olarak tanımlayabilirsiniz.
- Değişkenlere özel nitelikler (readonly, local vb.) atayabilirsiniz.
- **"declare"** komutu, sadece tanımlandığı kabuk oturumu veya kabuk betiği içinde geçerli olan değişkenler oluşturmanıza olanak sağlar.
- Yani, alt kabuk süreçlerinde geçerli olmazlar.
```
declare -i num=10
```
- 'num' değişkeni tamsayı olarak tanımlanır.
```
declare -r readonly_var="Hello"
```
- 'readonly_var' değişkeni salt okunur olarak tanımlanır.
```
declare -x exported_var="World"
```
- 'exported_var' değişkeni kabuk ortamına aktarılır.
```
declare -a my_array=(1 2 3)
```
- 'my_array' değişkeni dizi olarak tanımlanır.
```
declare -f my_function
```
- 'my_function' isimli bir işlev tanımlanır.

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

<br>

## 3. Redirections - Yönlendirmeler

### 3.1 Giriş Yönlendirme

- "<" sembolü, bir dosyadan giriş almak için kullanılan bir yönlendirme işlemidir. Bu işlem, bir komutun girişini, belirtilen bir dosyanın içeriğiyle değiştirir.
- Bir komut çalıştırıldığında, genellikle kullanıcının klavyeden giriş yapması beklenir. Ancak '<' sembolü kullanılarak, komutun girişi belirli bir dosyadan alınabilir.
- Bu, komutun klavyeden giriş almak yerine, belirli bir dosyayı giriş olarak kullanmasını sağlar.

```
sort < girdi.txt
```
- Örneğin aşağıdaki komutta 'sort' komutunu çalıştırırken girişi "girdi.txt" adlı dosyadan alır. Yani, girdi.txt dosyasının içeriği sort komutunun girişi olarak kullanılır.


### 3.2 Çıkış Yönlendirme
- '>' sembolü, bir komutun çıktısını belirtilen bir dosyaya yönlendirmek için kullanılan bir yönlendirme işlemidir.
- Bu işlem, komutun çıktısını bir dosyaya yazarak, komutun normalde ekrana veya standart çıktıya yazdığı çıktıyı dosyaya kaydetmek için kullanılır.

```
ls > dosya.txt
```
- Bu komut, ls komutunu çalıştırırken, çıktısını dosya.txt adlı bir dosyaya yönlendirir. 
- Yani, ls komutunun normalde ekrana yazdığı dosya ve dizin listesi, bu sefer dosya.txt adlı dosyaya yazılır.













