#ifndef DRS4HEADER_H
#define DRS4HEADER_H
struct FHEADER {
   char           tag[3];
   char           version;
};

struct THEADER{
   char           time_header[4];
};

struct BHEADER{
   char           bn[2];
   unsigned short board_serial_number;
};

struct EHEADER{
   char           event_header[4];
   unsigned int event_serial_number;
   unsigned short year;
   unsigned short month;
   unsigned short day;
   unsigned short hour;
   unsigned short minute;
   unsigned short second;
   unsigned short millisecond;
   unsigned short range;
};

typedef struct {
   char           tc[2];
   unsigned short trigger_cell;
} TCHEADER;

typedef struct {
   char           c[1];
   char           cn[3];
} CHEADER;


#endif // DRS4HEADER_H
