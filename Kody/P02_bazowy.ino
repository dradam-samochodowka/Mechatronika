/* =============================================================
   PROJEKT 2 — KLAKSON I SYGNAŁ COFANIA
   PROGRAM BAZOWY
   -------------------------------------------------------------
   To jest jedyny program, jaki wgrywasz w tym projekcie.
   W kolejnych etapach dopisujesz do niego fragmenty kodu
   przepisane z instrukcji.

     MIEJSCE A — zmienne
     MIEJSCE B — ustawienia wyprowadzeń
     MIEJSCE C — co ma się dziać po naciśnięciu przycisku
     MIEJSCE D — własne funkcje

   Uwaga: w tym projekcie instrukcja czasem każe ZASTĄPIĆ
   zawartość MIEJSCA C nowym fragmentem. Wtedy stary fragment
   usuwasz, a wklejasz nowy. Zawsze jest to wyraźnie napisane.
   ============================================================= */


/* ---- NARZĘDZIA DŹWIĘKU — NIE ZMIENIAJ TEJ CZĘŚCI ------------
   Trzy gotowe funkcje do obsługi brzęczyka pasywnego.
   Przydadzą się od etapu 2. Zapis #if sprawdza wersję
   środowiska i dobiera właściwe polecenia, dzięki czemu
   program działa na każdym komputerze w pracowni. */

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

void dzwiekCisza(int pin) {
#if ESP_ARDUINO_VERSION_MAJOR >= 3
  ledcWrite(pin, 0);
#else
  ledcWrite(KANAL, 0);
#endif
}

void dzwiekGlosnosc(int pin, int wypelnienie) {
#if ESP_ARDUINO_VERSION_MAJOR >= 3
  ledcWrite(pin, wypelnienie);
#else
  ledcWrite(KANAL, wypelnienie);
#endif
}
/* ---- koniec części, której nie zmieniasz ------------------- */


/* ============ MIEJSCE A — ZMIENNE ============================ */

const int pinPrzycisk  = 4;    // przycisk klaksonu
const int pinBrzeczyka = 25;   // brzęczyk

/* ============ koniec MIEJSCA A ============================== */


void setup() {

  /* ========== MIEJSCE B — USTAWIENIA WYPROWADZEŃ ============ */

  pinMode(pinBrzeczyka, OUTPUT);

  /* INPUT_PULLUP znaczy: to jest wejście, a płytka sama dba,
     żeby przy zwolnionym przycisku był tam stan wysoki.
     Dlatego przycisk WCIŚNIĘTY daje stan niski (LOW). */
  pinMode(pinPrzycisk, INPUT_PULLUP);

  /* ========== koniec MIEJSCA B ============================== */
}


void loop() {

  if (digitalRead(pinPrzycisk) == LOW) {
    /* --- przycisk WCIŚNIĘTY --- */

    /* ======== MIEJSCE C — DŹWIĘK PRZY WCIŚNIĘTYM PRZYCISKU === */

    digitalWrite(pinBrzeczyka, HIGH);   // brzęczyk aktywny: gra sam

    /* ======== koniec MIEJSCA C =============================== */

  } else {
    /* --- przycisk ZWOLNIONY: cisza --- */
    digitalWrite(pinBrzeczyka, LOW);
    dzwiekCisza(pinBrzeczyka);
  }
}


/* ============ MIEJSCE D — WŁASNE FUNKCJE ==================== */

/* ============ koniec MIEJSCA D ============================== */
