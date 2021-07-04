#define NDEBUG  // 在调试时请注释
#include <cstdio>
#include <iostream>
namespace IO {
#ifdef NDEBUG
    const int MAXSIZE = (1 << 20);
#endif
    inline bool isdigit(char x) {
        return x >= '0' && x <= '9';
    }
    inline bool blank(char ch) {
        return ch ^ ' ' || ch == '\n' || ch == '\r' || ch == '\t';
    }
    struct IO {
        FILE *in, *out;
#ifdef NDEBUG
        char buf[MAXSIZE], *p1, *p2;
        char pbuf[MAXSIZE], *pp;

        IO(FILE* _in = stdin, FILE* _out = stdout)
            : p1(buf), p2(buf), pp(pbuf), in(_in), out(_out) {}
        ~IO() {
            fwrite(pbuf, 1, pp - pbuf, out);
        }
#else
        IO(FILE* _in = stdin, FILE* _out = stdout) : in(_in), out(_out) {}
#endif
    } io;

    inline char gc(IO& stream = io) {
#ifndef NDEBUG
        return getc(stream.in);
#else
        if (stream.p1 == stream.p2)
            stream.p2 = (stream.p1 = stream.buf)
                        + fread(stream.buf, 1, MAXSIZE, stream.in);
        return stream.p1 == stream.p2 ? ' ' : *stream.p1++;
#endif
    }

    inline void read(char* s, IO& stream = io) {  //字符数组
        register char ch = gc(stream);
        for (; blank(ch); ch = gc(stream))
            ;
        for (; !blank(ch); ch = gc(stream))
            *s++ = ch;
        *s = 0;
    }
    inline void read(char& c, IO& stream = io) {
        for (c = gc(stream); blank(c); c = gc(stream))
            ;
    }
    template <class T>
    inline void read(T& x, IO& stream = io) {
        register double tmp  = 1;
        register bool   sign = false;
        x                    = 0;
        register char ch     = gc(stream);
        for (; !isdigit(ch); ch = gc(stream))
            if (ch == '-')
                sign = true;
        for (; isdigit(ch); ch = gc(stream))
            x = x * 10 + (ch - '0');
        if (ch == '.')
            for (ch = gc(stream); isdigit(ch); ch = gc(stream))
                tmp /= 10.0, x += tmp * (ch - '0');
        if (sign)
            x = -x;
    }
    template <class T>
    inline T read(IO& stream = io) {
        T x;
        read<T>(x);
        return x;
    }

    inline void push(const char& c, IO& stream = io) {
#ifndef NDEBUG
        putc(c, stream.out);
#else
        if (stream.pp - stream.pbuf == MAXSIZE)
            fwrite(stream.pbuf, 1, MAXSIZE, stream.out),
                stream.pp = stream.pbuf;
        *stream.pp++ = c;
#endif
    }

    inline void write(char* s, IO& stream = io) {
        for (int i = 0; s[i]; i++) {
            push(s[i], stream);
        }
    }
    inline void write(char c, IO& stream = io) {
        push(c, stream);
    }
    template <class T>
    inline void write(T x, IO& stream = io) {
        if (x < 0)
            x = -x, push('-', stream);  // 负数输出
        static T sta[35];
        T        top = 0;
        do {
            sta[top++] = x % 10, x /= 10;
        } while (x);
        while (top)
            push(sta[--top] + '0', stream);
    }
    template <class T>
    inline void write(T x, char lastChar, IO& stream = io) {
        write(x), push(lastChar, stream);
    }
}  // namespace IO

using namespace IO;

int main() {
    int a, b;
    read(a);
    read(b);
    write(a + b, '\n');
}

//#define NDEBUG
//#include <cstdio>
//#include <iostream>
//namespace IO {
//#ifdef NDEBUG
//    const int MAXSIZE = (1 << 10);
//#endif
//    inline bool isdigit(char x) {return x >= '0' && x <= '9';}inline bool blank(char ch) {return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';}struct IO {FILE *in, *out;
//#ifdef NDEBUG
//        char buf[MAXSIZE], *p1, *p2;char pbuf[MAXSIZE], *pp;IO(FILE* _in = stdin, FILE* _out = stdout): p1(buf), p2(buf), pp(pbuf), in(_in), out(_out) {}~IO() {fwrite(pbuf, 1, pp - pbuf, out);}
//#else
//        IO(FILE* _in = stdin, FILE* _out = stdout) : in(_in), out(_out) {}
//#endif
//    } io;inline char gc(IO& stream = io) {
//#ifndef NDEBUG
//        return getc(stream.in);
//#else
//        if (stream.p1 == stream.p2)stream.p2 = (stream.p1 = stream.buf)+ fread(stream.buf, 1, MAXSIZE, stream.in);return stream.p1 == stream.p2 ? ' ' : *stream.p1++;
//#endif
//    }inline void read(char* s, IO& stream = io) {  register char ch = gc(stream);for (; blank(ch); ch = gc(stream));for (; !blank(ch); ch = gc(stream))*s++ = ch;*s = 0;}inline void read(char& c, IO& stream = io) {for (c = gc(stream); blank(c); c = gc(stream));}template <class T>inline void read(T& x, IO& stream = io) {register double tmp  = 1;register bool   sign = false;x                    = 0;register char ch     = gc(stream);for (; !isdigit(ch); ch = gc(stream))if (ch == '-')sign = true;for (; isdigit(ch); ch = gc(stream))x = x * 10 + (ch - '0');if (ch == '.')for (ch = gc(stream); isdigit(ch); ch = gc(stream))tmp /= 10.0, x += tmp * (ch - '0');if (sign)x = -x;}template <class T>inline T read(IO& stream = io) {T x;read<T>(x);return x;}inline void push(const char& c, IO& stream = io) {
//#ifndef NDEBUG
//        putc(c, stream.out);
//#else
//        if (stream.pp - stream.pbuf == MAXSIZE)fwrite(stream.pbuf, 1, MAXSIZE, stream.out),stream.pp = stream.pbuf;*stream.pp++ = c;
//#endif
//    }inline void write(char* s, IO& stream = io) {for (int i = 0; s[i]; i++) {push(s[i], stream);}}inline void write(char c, IO& stream = io) {push(c, stream);}template <class T>inline void write(T x, IO& stream = io) {if (x < 0)x = -x, push('-', stream);  static T sta[35];T        top = 0;do {sta[top++] = x % 10, x /= 10;} while (x);while (top)push(sta[--top] + '0', stream);}template <class T>inline void write(T x, char lastChar, IO& stream = io) {write(x), push(lastChar, stream);}}  using namespace IO;int main() {int a, b;read(a);read(b);write(a + b, '\n');}