#include "common.h"
#include "FixedSizeStringBuilder.hpp"

TEST_CASE ("test - FixedSizeStringBuilder", "[FixedSizeStringBuilder]") {
    SECTION ("Enough buffer") {
        std::array <char, 256> buf;
        buf.fill (0xFF);
        SECTION ("Append ('a')") {
            FixedSizeStringBuilder sb { buf.data (), buf.size () };

            sb.Append ('a');
            REQUIRE (sb.GetLength () == 1);
            REQUIRE (buf[0] == 'a');
            REQUIRE (buf[1] == 0);
            REQUIRE (buf[2] == '\xFF');
        }
        SECTION ("Append (\"abc\"") {
            const char *str = "abc";
            size_t                 len = strlen (str);
            FixedSizeStringBuilder sb { buf.data (), buf.size () };

            sb.Append (str);
            REQUIRE (sb.GetLength () == len);
            REQUIRE (buf[len] == 0);
            REQUIRE (buf[len + 1] == '\xFF');
            REQUIRE (memcmp (buf.data (), str, len) == 0);
        }
    }
    SECTION ("Append (\"abcdefghijklmnopqrstuvwxyz\" to smaller sized buffer") {
        std::array<char, 16>    buf ;
        buf.fill (0xFF) ;

        const char *    str = "abcdefghijklmnopqrstuvwxyz" ;
        size_t len = strlen (str) ;
        FixedSizeStringBuilder  sb { buf.data (), buf.size () } ;

        sb.Append (str) ;
        REQUIRE (sb.GetLength () == buf.size () - 1) ;
        REQUIRE (buf [buf.size () - 1] == 0) ;
        REQUIRE (memcmp (buf.data (), str, buf.size () - 1) == 0) ;
    }
    SECTION ("\"abcde\" + \"abcde\" to smaller buffer") {
        std::array<char, 10>    buf ;
        buf.fill (0xFF) ;

        const char *    str = "abcde";
        size_t  len = strlen (str);

        FixedSizeStringBuilder  sb { buf.data (), buf.size () } ;

        sb.Append (str).Append (str);
        REQUIRE (sb.GetLength () == (buf.size () - 1));
        REQUIRE (buf [buf.size () - 1] == 0);
        REQUIRE (memcmp (buf.data (), "abcdeabcde", buf.size () - 1) == 0) ;
    }
    SECTION ("AppendWithFormat") {
        SECTION ("AppendWithFormat (\"%s\", \"abcdefghij\")") {
            std::array<char, 11>    buf ;
            buf.fill (0xFF) ;

            FixedSizeStringBuilder  sb { buf.data (), buf.size () };

            const char *    str = "abcdefghij" ;
            sb.AppendWithFormat ("%s", str) ;
            REQUIRE (sb.GetLength () == buf.size () - 1) ;
            REQUIRE (buf [buf.size () - 1] == 0) ;
            REQUIRE (memcmp (buf.data (), str, buf.size () - 1) == 0) ;
        }
        SECTION ("AppendWithFormat (\"%s\", \"abcdefghij\")") {
            std::array<char, 10>    buf ;
            buf.fill (0xFF) ;

            FixedSizeStringBuilder  sb { buf.data (), buf.size () };

            const char *    str = "abcdefghij" ;
            sb.AppendWithFormat ("%s", str) ;
            REQUIRE (sb.GetLength () == buf.size () - 1) ;
            REQUIRE (buf [buf.size () - 1] == 0) ;
            REQUIRE (memcmp (buf.data (), str, buf.size () - 1) == 0) ;
        }
    }
}

