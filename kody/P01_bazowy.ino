/* =============================================================
   PROJEKT 1 — KIERUNKOWSKAZY I ŚWIATŁA AWARYJNE
   PROGRAM BAZOWY
   -------------------------------------------------------------
   To jedyny program, jaki wgrywasz w tym projekcie.
   W kolejnych etapach NIE dostajesz nowych plików — dopisujesz
   do tego programu fragmenty kodu przepisane z instrukcji.

     MIEJSCE A — zmienne (numery wyprowadzeń, czasy)
     MIEJSCE B — ustawienia wyprowadzeń, wykonywane raz na starcie
     MIEJSCE C — sterowanie światłami, powtarzane bez końca
     MIEJSCE D — własne funkcje

   Zasada: do MIEJSC dopisujesz. Usuwasz tylko wtedy, gdy
   instrukcja wyraźnie każe coś zastąpić.

   UWAGA: w etapach 6 i 7 rozbierasz układ i budujesz go od nowa.
   Instrukcja powie Ci o tym wyraźnie.
   ============================================================= */


/* ============ MIEJSCE A — ZMIENNE ============================
   Zmienna to pudełko z nazwą, w którym trzymamy jedną wartość.
   Zapis "const int" znaczy: liczba całkowita, która się nie zmieni.
   ============================================================= */

const int pinDiodaL = 17;      // dioda lewego kierunkowskazu

int czasMigania = 800;         // ile milisekund świeci, a potem ile gaśnie
                               // jeden pełny cykl = 2 x czasMigania

/* ============ koniec MIEJSCA A ============================== */


/* --- Poniższe dwie zmienne obsługują zegar migania.
       Nie musisz ich zmieniać. --- */
bool swieci = false;                 // czy w tej chwili jest faza świecenia
unsigned long ostatniaZmiana = 0;    // kiedy ostatnio przełączyliśmy fazę


void setup() {
  /* setup wykonuje się RAZ, zaraz po włączeniu płytki. */

  /* ========== MIEJSCE B — USTAWIENIA WYPROWADZEŃ ============ */

  pinMode(pinDiodaL, OUTPUT);

  /* ========== koniec MIEJSCA B ============================== */
}


void loop() {
  /* loop wykonuje się W KÓŁKO, tysiące razy na sekundę. */

  /* --- ZEGAR MIGANIA ---
     millis() podaje, ile milisekund minęło od włączenia płytki.
     Gdy od ostatniej zmiany minie czasMigania, przełączamy fazę.
     Używamy tego zamiast delay(), bo delay() zatrzymałby cały
     program i nie dałoby się jednocześnie czytać przycisków. */
  if (millis() - ostatniaZmiana >= czasMigania) {
    ostatniaZmiana = millis();
    swieci = !swieci;            // wykrzyknik odwraca: prawda <-> fałsz
  }

  /* ========== MIEJSCE C — STEROWANIE ŚWIATŁAMI ============== */

  digitalWrite(pinDiodaL, swieci);

  /* ========== koniec MIEJSCA C ============================== */
}


/* ============ MIEJSCE D — WŁASNE FUNKCJE ====================
   Funkcja to fragment kodu z własną nazwą, który można wywołać
   z dowolnego miejsca. Na razie pusto — pojawi się w etapie 6.
   ============================================================= */

/* ============ koniec MIEJSCA D ============================== */
