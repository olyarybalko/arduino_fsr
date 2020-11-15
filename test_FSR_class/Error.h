#ifndef ERROR_H
#define ERROR_H

// constante qui affichera le mot done sur LED à 7-segments.
const uint8_t SEG_DONE[] = {
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,           // d
  SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F,   // O
  SEG_C | SEG_E | SEG_G,                           // n
  SEG_A | SEG_D | SEG_E | SEG_F | SEG_G            // E
};

// constante qui affichera Erreur sur LED à 7-segments, si la force d'appui est superieure de 9999 gramme.
const uint8_t SEG_ERR_MAX[] = {
  SEG_F,
  SEG_F,
  SEG_F,
  SEG_F
};

// constante qui affichera Erreur de connexion de button sur LED à 7-segments.
const uint8_t SEG_ERR_BUTTON[] = {
  SEG_D,
  SEG_D,
  SEG_D,
  SEG_D
};

// constante qui affichera Erreur de connexion de FSR sur LED à 7-segments.
const uint8_t SEG_ERR_FSR[] = {
  SEG_A,
  SEG_A,
  SEG_A,
  SEG_A
};

// constante qui affichera Erreur de connexion de FSR1 sur LED à 7-segments.
const uint8_t SEG_ERR_FSR1[] = {
  SEG_B,
  SEG_B,
  SEG_B,
  SEG_B
};

// constante qui affichera Erreur de connexion de FSR2 sur LED à 7-segments.
const uint8_t SEG_ERR_FSR2[] = {
  SEG_C,
  SEG_C,
  SEG_C,
  SEG_C
};
#endif
