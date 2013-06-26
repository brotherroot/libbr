/** 
 * @file  include/math/XYPair.hpp
 */
#pragma once

#include <config.hpp>

#include <ios>
#include <sstream>

namespace BR {

template< class Tp >
struct XYPair {
	BR_VALTYPE_SERIES( Tp )
	BR_SELFTYPE_SERIES( XYPair<ValType> )

	typedef ValType value_type;

	ValType x, y;

	BR_CONSTEXPR XYPair( void ) : x(), y() { }

	template< class Up >
	BR_CONSTEXPR XYPair( XYPair< Up > const & src ) : x( src.x ), y( src.y ) { }

	template<class Up, class Vp >
	BR_CONSTEXPR XYPair( Up const & xx, Vp const & yy ) : x( xx ), y( yy ) { }
	/*
	 *  assignment
	 */
	template< class Up >
	SelfRefType assign( XYPair< Up > const & src ) {
		x = src.x;
		y = src.y;
		return *this;
	}

	template< class Up, class Vp >
	SelfRefType assign( Up const & xx, Vp const & yy ) {
		x = xx;
		y = yy;
		return *this;
	}

	template< class Up >
	SelfRefType assign( Up const & rhs ) {
		y = x = rhs;
		return *this;
	}

	template< class Up >
	SelfRefType add_assign( XYPair< Up > const & rhs ) const {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	template< class Up >
	SelfRefType sub_assign( XYPair< Up > const & rhs ) const {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	template< class Up, class Vp >
	SelfRefType add_assign( Up const & rhsx, Vp const & rhsy ) const {
		x += rhsx;
		y += rhsy;
		return *this;
	}

	template< class Up, class Vp >
	SelfRefType sub_assign( Up const & rhsx, Vp const & rhsy ) const {
		x -= rhsx;
		y -= rhsy;
		return *this;
	}

	template< class Up >
	SelfRefType mul_assign( Up const & rhs ) const {
		x *= rhs;
		y *= rhs;
		return *this;
	}

	template< class Up >
	SelfRefType div_assign( Up const & rhs ) const {
		x /= rhs;
		y /= rhs;
		return *this;
	}

	template< class Up >
	SelfRefType add_assign( Up const & rhs ) const {
		x += rhs;
		y += rhs;
		return *this;
	}

	template< class Up >
	SelfRefType sub_assign( Up const & rhs ) const {
		x -= rhs;
		y -= rhs;
		return *this;
	}

	template< class Up >
	BR_CONSTEXPR bool eql( XYPair< Up > const & rhs ) const {
		return x == rhs.x && y == rhs.y;
	}

	template< class Up >
	BR_CONSTEXPR bool neq( XYPair< Up > const & rhs ) const {
		return x != rhs.x || y != rhs.y;
	}

	template< class Up, class Vp >
	BR_CONSTEXPR bool eql( Up const & rhsx, Vp const & rhsy ) const {
		return x == rhsx && y == rhsy;
	}

	template< class Up, class Vp > 
	BR_CONSTEXPR bool neq( Up const & rhsx, Vp const & rhsy ) const {
		return x != rhsx || y != rhsy;
	}

	template< class Up, class Vp >
	BR_CONSTEXPR static bool order_x(
		XYPair< Up > const & lhs,
		XYPair< Vp > const & rhs
	) {
		return lhs.x < rhs.x || lhs.x == rhs.x && lhs.y < rhs.y;
	}

	template< class Up, class Vp >
	BR_CONSTEXPR static bool order_y(
		XYPair< Up > const & lhs,
		XYPair< Vp > const & rhs
	) {
		return lhs.y < rhs.y || lhs.y == rhs.y && lhs.x < rhs.x;
	}

	template<class Up >
	BR_CONSTEXPR SelfRefType operator=( XYPair< Up > const & src ) {
		return assign( src );
	}

	template< class Up >
	BR_CONSTEXPR SelfRefType operator+=( XYPair< Up > const & rhs ) {
		return add_assign( rhs );
	}
	
	template< class Up >
	BR_CONSTEXPR SelfRefType operator-=( XYPair< Up > const & rhs ) {
		return sub_assign( rhs );
	}

	template<class Up >
	BR_CONSTEXPR SelfRefType operator=( Up const & rhs ) {
		return assign( rhs );
	}

	template< class Up >
	BR_CONSTEXPR SelfRefType operator+=( Up const & rhs ) {
		return add_assign( rhs );
	}
	
	template< class Up >
	BR_CONSTEXPR SelfRefType operator-=( Up const & rhs ) {
		return sub_assign( rhs );
	}

	template< class Up >
	BR_CONSTEXPR SelfRefType operator*=( Up const & rhs )  {
		return mul_assign( rhs );
	}

	template< class Up >
	BR_CONSTEXPR SelfRefType operator/=( Up const & rhs )  {
		return div_assign( rhs );
	}
};

template< class ValType, class CharType, class CharTraits >
std::basic_istream< CharType, CharTraits > & operator>>(
	std::basic_istream< CharType, CharTraits > & istr,
	XYPair< ValType > & vec
) {
	ValType vecx, vecy;
	CharType ch;
	istr >> ch;
	if ( ch == '(' ) {
		istr >> vecx >> ch;
		if ( ch == ',' ) {
			istr >> vecy >> ch;
			if ( ch == ')' ) {
				vec = XYPair< ValType >( vecx, vecy );
			} else {
				istr.setstate( std::ios_base::failbit );
			}
		} else if ( ch == ')' ) {
			vec = XYPair< ValType >( vecx, ValType() );
		} else {
			istr.setstate( std::ios_base::failbit );
		}
	} else {
		istr >> vecx;
		vec = XYPair< ValType >( vecx, ValType() );
	}
	return istr;
}

template< class ValType, class CharType, class CharTraits >
std::basic_ostream< CharType, CharTraits >& operator<<(
	std::basic_ostream< CharType, CharTraits > & ostr,
	XYPair< ValType > const & rhs
) {
	std::basic_ostringstream< CharType, CharTraits > osstr;
	osstr.flags( ostr.flags() );
	osstr.imbue( ostr.getloc() );
	osstr.precision( ostr.precision() );
	osstr << '(' << rhs.x << ',' << rhs.y << ')';
	return ostr << osstr.str();
}

}
