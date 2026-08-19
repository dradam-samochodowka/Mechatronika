/* =============================================================
   PROJEKT 2 — KLAKSON I SYGNAŁ COFANIA
   PROGRAM BAZOWY
   -------------------------------------------------------------
   W tym projekcie MIEJSCE C jest podzielone na dwie części:

     MIEJSCE A  — zmienne
     MIEJSCE B  — ustawienia wyprowadzeń
     MIEJSCE C1 — co się dzieje, gdy przycisk jest WCIŚNIĘTY
     MIEJSCE C2 — co się dzieje, gdy przycisk jest ZWOLNIONY
     MIEJSCE D  — własne funkcje

   Podział na C1 i C2 jest ważny: wszystko, co włączasz w C1,
   musisz wyłączyć w C2. Inaczej klakson zostanie włączony
   na zawsze.

   DWIE RZECZY, KTÓRE MUSISZ WIEDZIEĆ O TYM UKŁADZIE:

   1. Brzęczyk — i aktywny, i pasywny — sterujemy ZAWSZE przez
      tranzystor. Brzęczyk potrafi pobrać prąd większy, niż
      dopuszcza pojedyncze wyprowadzenie płytki. Tranzystor
      bierze ten prąd na siebie, a płytka steruje tylko jego bazą.

   2. Obu brzęczyków używamy na TYM SAMYM wyprowadzeniu — po
      prostu wymieniasz element w układzie. Dlatego przez cały
      projekt sterujemy nim jednym sposobem: funkcjami dźwięku
      z części poniżej. NIE używamy tutaj digitalWrite.
      Mieszanie obu sposobów na jednym wyprowadzeniu powoduje,
      że brzęczyk buczy bez końca niskim tonem.

   UWAGA O GŁOŚNOŚCI: brzęczyk łączymy SZEREGOWO Z DIODĄ LED.
   Dioda obniża napięcie i ogranicza prąd, więc brzęczyk gra
   ciszej, a przy okazji widać, kiedy pracuje.
   ============================================================= */


/* ---- NARZĘDZIA DŹWIĘKU — NIE ZMIENIAJ TEJ CZĘŚCI ------------
   Cztery gotowe funkcje do obsługi brzęczyka.
   Zapis #if sprawdza wersję środowiska i dobiera właściwe
   polecenia, dzięki czemu program działa na każdym komputerze. */

const int KANAL = 0;

void dzwiekPrzygotuj(int pin) {
#if ESP_ARDUINO_VERSION_MAJOR >= 3
  ledcAttach(pin, 1000, 8);
#else
  ledcSetup(KANAL, 1000, 8);
  ledcAttachPin(pin, KANAL);
#endif
}

void dzwiekGraj(int pin, int czestotliwosc) {
#if ESP_ARDUINO_VERSION_MAJOR >= 3
  ledcWriteTone(pin, czestotliwosc);
#else
  ledcWriteTone(KANAL, czestotliwosc);
#endif
}

void dzwiekGlosnosc(int pin, int wypelnienie) {
#if ESP_ARDUINO_VERSION_MAJOR >= 3
  ledcWrite(pin, wypelnienie);
#else
  ledcWrite(KANAL, wypelnienie);
#endif
}

void dzwiekCisza(int pin) {
#if ESP_ARDUINO_VERSION_MAJOR >= 3
  ledcWrite(pin, 0);
#else
  ledcWrite(KANAL, 0);
#endif
}
/* ---- koniec części, której nie zmieniasz ------------------- */


/* ============ MIEJSCE A — ZMIENNE ============================ */

const int pinPrzycisk = 16;    // przycisk klaksonu

/* Wyprowadzenie sterujące tranzystorem, który załącza brzęczyk.
   Ten sam numer obowiązuje dla brzęczyka aktywnego i pasywnego —
   wymieniasz tylko element w układzie, nie połączenie z płytką. */
const int pinBrzeczyka = 17;

/* ============ koniec MIEJSCA A ============================== */


void setup() {

  /* ========== MIEJSCE B — USTAWIENIA WYPROWADZEŃ ============ */

  dzwiekPrzygotuj(pinBrzeczyka);

  /* INPUT_PULLUP znaczy: to jest wejście, a płytka sama dba,
     żeby przy zwolnionym przycisku był tam stan wysoki.
     Dlatego przycisk WCIŚNIĘTY daje stan niski (LOW). */
  pinMode(pinPrzycisk, INPUT_PULLUP);

  /* ========== koniec MIEJSCA B ============================== */
}


void loop() {

  if (digitalRead(pinPrzycisk) == LOW) {
    /* --- przycisk WCIŚNIĘTY --- */

    /* ======== MIEJSCE C1 — PRZYCISK WCIŚNIĘTY ================ */

    /* Wartość 255 to pełne wysterowanie, czyli napięcie podane
       na stałe. Brzęczykowi aktywnemu wystarczy to do grania —
       resztą zajmuje się jego własny układ w środku. */
    dzwiekGlosnosc(pinBrzeczyka, 255);

    /* ======== koniec MIEJSCA C1 ============================== */

  } else {
    /* --- przycisk ZWOLNIONY --- */

    /* ======== MIEJSCE C2 — PRZYCISK ZWOLNIONY ================ */

    dzwiekCisza(pinBrzeczyka);

    /* ======== koniec MIEJSCA C2 ============================== */
  }
}


/* ============ MIEJSCE D — WŁASNE FUNKCJE ==================== */

/* ============ koniec MIEJSCA D ============================== */
