#include <Arduino.h> //Mengimpor library utama Arduino
#include <LiquidCrystal_I2C.h> //Mengimpor library LCD
#include <Servo.h>//Mengimpor library untuk Servo

Servo myservo; //Menginisiasikan objek Servo

LiquidCrystal_I2C lcd(0x27,16,2); //Menginisiasikan objek LCD dengan constructor berisi parameter (alamat lcd, jumlah kolom, jumlah baris)
int SDA_pin = D3; //Membuat variabel untuk pin SDA disesuaikan penempatan pin nya
int SCL_pin = D7; //Membuat variabel untuk pin SCL disesuaikan penempatan pin nya

void setup() {
  myservo.attach(D4); // Menghubungkan pin D4 sebagai pin servo
  Wire.begin(SDA_pin,SCL_pin); // Memulai koneksi antara pin SDA dan pin SCL
  lcd.begin(16,2); //Memulai LCD
  lcd.init(); // Melakukan inisialisasi lcd
  lcd.backlight(); // Menyalakan backlight lcd
  myservo.write(0);// Memutar servo ke sudut awalnya yaitu 0
  Serial.begin(9600);// Memulai serial di 9600 jika dibutuhkan

}

void loop() {
  delayMicroseconds(3000); //Melakukan delay awal 3 detik
  myservo.write(180);// Memutar Servo 180 derajat atau 90 derajat untuk beberapa servo
  lcd.clear(); //Membersihkan layar lcd
  lcd.setCursor(0,0); // Koordinat ketikan awal di baris 0 kolom 0 lcd
  lcd.print("Status :"); // Menuliskan Status
  lcd.setCursor(0,1); //Koordinat ketikan awal di baris 1 kolom 0 lcd
  lcd.print("Pintu Terbuka"); // Menuliskan pintu terbuka
  delayMicroseconds(5000); // Mendelay 5 detik
  myservo.write(0);//Mengembalikan servo ke posisi semula.
  lcd.clear(); //Membersihkan layar lcd
  lcd.setCursor(0,0); // Koordinat ketikan awal di baris 0 kolom 0 lcd
  lcd.print("Status :"); // Menuliskan Status
  lcd.setCursor(0,1);//Koordinat ketikan awal di baris 1 kolom 0 lcd
  lcd.print("Pintu Tertutup"); // Menuliskan pintu tertutup
  
}

