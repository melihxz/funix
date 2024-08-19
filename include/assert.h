// include/assert.h

#ifndef ASSERT_H
#define ASSERT_H

// assert makrosu
#define assert(expression) \
    ((expression) ? (void)0 : __assert_fail(#expression, __FILE__, __LINE__, __func__))

void __assert_fail(const char *expression, const char *file, int line, const char *function);

#endif // ASSERT_H
