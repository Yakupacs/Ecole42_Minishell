<h1 align="center">
     MINISHELL
</h1>

### İçindekiler

1. [Shell Adımlar](#1-shell-adımlar)
     1. [Lexer](#11-lexer)
     2. [Parser](#12-parser)
     3. [Executor](#13-executor)
2. [Çalışma Yapısı](#2-çalışma-yapısı)
     1. [Yapı](#21-yapı)

<br>

## 1. Shell Adımlar


### 1.1 Lexer
##### Lexer, metin girdisini tararken belirli dilbilgisi kurallarına dayalı olarak metni analiz eder. Bash shell için lexer, girilen metni parçalara ayırır ve her parçayı birer "token" olarak tanımlar. Tokenler, komutlar, argümanlar, değişkenler, operatörler vb. gibi dilbilgisi yapılarını temsil eder. Lexer, metindeki karakterleri okur, bu karakterlerin anlamsal gruplara ayrılmasını sağlar ve daha sonra bu tokenlerin bir listesini oluşturur.

### 1.2 Parser
##### Parser, lexer tarafından oluşturulan token listesini alır ve bu tokenlerin belirli bir dilbilgisi yapısını takip ettiğini kontrol eder. Parser, dilbilgisi kurallarını kullanarak tokenleri işler, onları sözdizimsel olarak doğru bir şekilde sıralar ve dilin gramerine uygun bir ağaç yapısı oluşturur. Bash shell için parser, komutların doğru bir şekilde düzenlenmesini, argümanların ve seçeneklerin doğru yerleştirilmesini ve işaretçilerin (örneğin; ifadelerin bitişini veya döngülerin başlangıcını belirten belirteçler) doğru kullanılmasını kontrol eder.

### 1.3 Executor
##### Executor, parser tarafından oluşturulan dilbilgisi ağacını alır ve bu ağaçtaki her komut için bir işlem oluşturur. Bash shell için executor, komutları işletmek ve sonuçlarını elde etmekle sorumludur. Executor, komutları işletirken, değişkenleri değerlendirir, dosya işlemlerini gerçekleştirir, diğer programları çalıştırır ve gerektiğinde çıktıyı bir sonraki komuta yönlendirmek için boruları (pipe) oluşturur. Executor ayrıca koşullu ifadeleri değerlendirir, döngülerin döngü koşullarını kontrol eder ve program akışını yönetir.



## 2. Çalışma Yapısı


### 2.1 Yapı

![image](https://github.com/Yakupacs/Ecole42_Minishell/assets/73075252/95882bea-cef8-4113-9354-8da56ccaaa55)

