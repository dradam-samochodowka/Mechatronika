/* =============================================================
   PROJEKT 1 — KIERUNKOWSKAZY I ŚWIATŁA AWARYJNE
   PROGRAM BAZOWY
   -------------------------------------------------------------
   To jest jedyny program, jaki wgrywasz w tym projekcie.
   W kolejnych etapach NIE dostajesz nowych plików — dopisujesz
   do tego programu fragmenty kodu przepisane z instrukcji.

   W programie są cztery MIEJSCA oznaczone ramkami:

     MIEJSCE A — zmienne (numery wyprowadzeń, czasy)
     MIEJSCE B — ustawienia wyprowadzeń, wykonywane raz na starcie
     MIEJSCE C — sterowanie światłami, powtarzane bez końca
     MIEJSCE D — własne funkcje

   Zasada: do MIEJSC tylko DOPISUJESZ. Niczego nie usuwasz,
   chyba że instrukcja wyraźnie każe coś zastąpić.
   ============================================================= */


/* ============ MIEJSCE A — ZMIENNE ============================
   Zmienna to pudełko z nazwą, w którym trzymamy jedną wartość.
   Zapis "const int" znaczy: liczba całkowita, która się nie zmieni.
   ============================================================= */

const int pinDiodaL = 18;      // dioda lewego kierunkowskazu

int czasMigania = 800;         // ile milisekund świeci, a potem ile gaśnie
                               // jeden pełny cykl = 2 x czasMigania

/* ============ koniec MIEJSCA A ============================== */


/* --- Poniższe dwie zmienne obsługują zegar migania.
       Nie musisz ich zmieniać. --- */
bool swieci = false;                 // czy w tej chwili jest faza świecenia
unsigned long ostatniaZmiana = 0;    // kiedy ostatnio przełączyliśmy fazę


void setup() {
  /* setup wykonuje się RAZ, zaraz po włączeniu płytki.
     Tutaj mówimy, które wyprowadzenia mają sterować (OUTPUT),
     a które czytać (INPUT_PULLUP). */

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
