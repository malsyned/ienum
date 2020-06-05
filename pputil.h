#ifndef PPUTIL_H
#define PPUTIL_H

#define concat(a, b) a ## b
#define econcat(a, b) concat(a, b)

#define stringify(a) #a
#define estringify(a) stringify(a)

#endif /* !PPUTIL_H */
