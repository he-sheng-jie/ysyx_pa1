#ifndef __IRINGBUF_H__
#define __IRINGBUF_H__

#define IRINGBUF_SIZE 16

void iringbuf_record(const char *logbuf);
void iringbuf_dump();

#endif