/* ISC license. */

#include <sys/types.h>
#include <skalibs/buffer.h>
#include <execline/execline.h>

static int next (unsigned char *c, void *p)
{
  ssize_t r = buffer_get((buffer *)p, (char *)c, 1) ;
  if (r < 0) return 0 ;
  if (!r) *c = 0 ;
  return 1 ;
}

int el_parse_from_buffer (stralloc *sa, buffer *b)
{
  return el_parse(sa, &next, b) ;
}
