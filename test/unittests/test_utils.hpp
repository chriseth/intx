// intx: extended precision integer library.
// Copyright 2019-2020 Pawel Bylica.
// Licensed under the Apache License, Version 2.0.
#pragma once

#include <intx/int128.hpp>

#if __cpp_exceptions
    #define EXPECT_THROW_MESSAGE(stmt, ex_type, expected)                                        \
        try                                                                                      \
        {                                                                                        \
            stmt;                                                                                \
            ADD_FAILURE() << "Exception of type " #ex_type " is expected, but none was thrown."; \
        }                                                                                        \
        catch (const ex_type& exception)                                                         \
        {                                                                                        \
            EXPECT_STREQ(exception.what(), expected);                                            \
        }                                                                                        \
        (void)0
#else
    #define EXPECT_THROW_MESSAGE(stmt, ex_type, expected) EXPECT_DEATH(stmt, expected)
#endif


struct type_to_name
{
    template <typename T>
    static std::string GetName(int i);
};

template <>
inline std::string type_to_name::GetName<intx::uint<128>>(int)
{
    return "uint128";
}

template <>
inline std::string type_to_name::GetName<intx::uint<256>>(int)
{
    return "uint256";
}

template <>
inline std::string type_to_name::GetName<intx::uint<512>>(int)
{
    return "uint512";
}
