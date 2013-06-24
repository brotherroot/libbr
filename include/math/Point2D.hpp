
/** 
 * @file  include/math/Point2D.hpp
 */
#pragma once

#include <config.hpp>

#include HEADER_MATH
#include <ios>
#include <sstream>

#ifdef USING_STD_CPP11
#include <type_traits>
#endif // USING_STD_CPP11

namespace BR {
/**
 *  @brief 2D point
 *  @ingroup math
 *  @param  Tp  type of element
 */
template<class Tp>
struct Vector2D;

template<class Tp>
struct Point2D {
	typedef Tp ValType;
	typedef ValType value_type;
	typedef Point2D<ValType>  SelfType;
	typedef SelfType const    CSelfType;
	typedef SelfType  &       SelfRefType;
	typedef CSelfType &       CSelfRefType;
	typedef Vector2D<ValType> VecType;

	ValType x, y;
	/*
	 *  constructor
	 */
	BR_CONSTEXPR Point2D( void ) : x(), y() { }

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR explicit Point2D( Point2D< Up > const & src )
		: x( src.x ), y( src.y ) { }

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR explicit Point2D( Vector2D< Up > const & vec )
		: x( vec.x ), y( vec.y ) { }

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR explicit Point2D( Point2D< Up > const & src, Vector2D< Vp > const & vec )
		: x( src.x + vec.x ), y( src.y + vec.y ) { }

	template<class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR Point2D( Up const & xx, Vp const & yy )
		: x( xx ), y( yy ) { }
	/*
	 *  assignment
	 */
	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	SelfRefType assign( Point2D< Up > const & src ) {
		x = src.x;
		y = src.y;
		return *this;
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	SelfRefType assign( Vector2D< Up > const & src ) {
		x = src.x;
		y = src.y;
		return *this;
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	SelfRefType assign( Point2D< Up > const & src, Vector2D< Vp > const & vec ) {
		x = src.x + vec.x;
		y = src.y + vec.y;
		return *this;
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	SelfRefType assign( Up const & xx, Vp const & yy ) {
		x = xx;
		y = yy;
		return *this;
	}
	/*
	 *  operation
	 */
	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR VecType sub( Point2D< Up > const & rhs ) const { 
		return VecType( x - rhs.x, y - rhs.y );
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR SelfType add( Vector2D< Up > const & rhs ) const { 
		return SelfType( x + rhs.x, y + rhs.y );
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR SelfType sub( Vector2D< Up > const & rhs ) const { 
		return SelfType( x - rhs.x, y - rhs.y );
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR SelfType add( Up const & rhsx, Vp const & rhsy ) const {
		return SelfType(x + rhsx, y + rhsy);
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR SelfType sub( Up const & rhsx, Vp const & rhsy ) const {
		return SelfType( x - rhsx, y - rhsy );
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	SelfRefType self_add( Vector2D< Up > const & rhs ) const {
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	SelfRefType self_sub( Vector2D< Up > const & rhs ) const {
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	SelfRefType self_add( Up const & rhsx, Vp const & rhsy ) const {
		x += rhsx;
		y += rhsy;
		return *this;
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	SelfRefType self_sub( Up const & rhsx, Vp const & rhsy ) const {
		x -= rhsx;
		y -= rhsy;
		return *this;
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR bool eql( Point2D< Up > const & rhs ) const {
		return x == rhs.x && y == rhs.y;
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR bool neq( Point2D< Up > const & rhs ) const {
		return x != rhs.x || y != rhs.y;
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR bool eql( Up const & rhsx, Vp const & rhsy ) const {
		return x == rhsx && y == rhsy;
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) > 
	BR_CONSTEXPR bool neq( Up const & rhsx, Vp const & rhsy ) const {
		return x != rhsx || y != rhsy;
	}

	BR_CONSTEXPR ValType dist_sqr( void ) const {
		return x * x + y * y;
	}

	BR_CONSTEXPR ValType dist( void ) const {
		return std::sqrt( x * x + y * y );
	}

	BR_CONSTEXPR ValType arg( void ) const {
		return std::atan2( y, x );
	}

	BR_CONSTEXPR ValType tan_arg( void ) const {
		return y / x;
	}
	/*
	 *  operator
	 */
	template<class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR SelfRefType operator=( Point2D< Up > const & src ) {
		return assign( src );
	}

	BR_CONSTEXPR SelfRefType operator+( void ) {
		return *this;
	}

	BR_CONSTEXPR CSelfRefType operator+( void ) const {
		return *this;
	}

	BR_CONSTEXPR SelfType operator-( void ) const {
		return SelfType( -x, -y );
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR static ValType Hamilton_dist(
		Point2D< Up > const & lhs,
		Point2D< Vp > const & rhs
	) {
		return std::abs( ValType( lhs.x - rhs.x ) ) + std::abs( ValType (lhs.y - rhs.y ) );
	}

	template< class Up, class Vp >
	BR_CONSTEXPR static ValType Euclid_dist_sqr(
		Point2D< Up > const & lhs,
		Point2D< Vp > const & rhs
	) {
		return SelfType( lhs, rhs ).norm_sqr();
	}

	template< class Up, class Vp >
	BR_CONSTEXPR static ValType Euclid_dist(
		Point2D< Up > const & lhs,
		Point2D< Vp > const & rhs
	) {
		return SelfType( lhs, rhs ).norm();
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR static  bool order_x(
		Point2D< Up > const & lhs,
		Point2D< Vp > const & rhs
	) {
		return lhs.x < rhs.x || lhs.x == rhs.x && y < rhs.y;
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR static bool order_y(
		Point2D< Up > const & lhs,
		Point2D< Vp > const & rhs
	) {
		return lhs.y < rhs.y || lhs.y == rhs.y && x < rhs.x;
	}
};

template< class Tp, class Up >
BR_CONSTEXPR inline Vector2D< Tp > operator-(
	Point2D< Tp > const & lhs,
	Point2D< Up > const & rhs
) {
	return lhs.sub( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Point2D< Tp > operator+(
	Point2D< Tp > const & lhs,
	Vector2D< Up > const & rhs
) {
	return lhs.add( rhs );
}
	
template< class Tp, class Up >
BR_CONSTEXPR inline Point2D< Tp > operator-(
	Point2D< Tp > const & lhs,
	Vector2D< Up > const & rhs
) {
	return lhs.sub( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Point2D< Tp > & operator+=(
	Point2D< Tp > & lhs,
	Vector2D< Up > const & rhs
) {
	return lhs.self_add( rhs );
}
	
template< class Tp, class Up >
BR_CONSTEXPR inline Point2D< Tp > & operator-=(
	Point2D< Tp > & lhs,
	Vector2D< Up > const & rhs
) {
	return lhs.self_sub( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline bool operator==(
	Point2D< Tp > const & lhs,
	Point2D< Up > const & rhs
) {
	return lhs.eql(rhs);
}

template< class Tp, class Up >
BR_CONSTEXPR inline bool operator!=(
	Point2D< Tp > const & lhs,
	Point2D< Up > const & rhs
) {
	return lhs.neq(rhs);
}

template< class ValType, class CharType, class CharTraits >
std::basic_istream< CharType, CharTraits > & operator>>(
	std::basic_istream< CharType, CharTraits > & istr,
	Point2D< ValType > & vec
) {
	ValType vecx, vecy;
	CharType ch;
	istr >> ch;
	if ( ch == '(' ) {
		istr >> vecx >> ch;
		if ( ch == ',' ) {
			istr >> vecy >> ch;
			if ( ch == ')' ) {
				vec = Point2D< ValType >( vecx, vecy );
			} else {
				istr.setstate( std::ios_base::failbit );
			}
		} else if ( ch == ')' ) {
			vec = Point2D< ValType >( vecx, ValType() );
		} else {
			istr.setstate( std::ios_base::failbit );
		}
	} else {
		istr >> vecx;
		vec = Point2D< ValType >( vecx, ValType() );
	}
	return istr;
}

template< class ValType, class CharType, class CharTraits >
std::basic_ostream< CharType, CharTraits >& operator<<(
	std::basic_ostream< CharType, CharTraits > & ostr,
	Point2D< ValType > const & rhs
) {
	std::basic_ostringstream< CharType, char_traits> osstr;
	osstr.flags( ostr.flags() );
	osstr.imbue( ostr.getloc() );
	osstr.precision( ostr.precision() );
	osstr << '(' << rhs.x << ',' << rhs.y << ')';
	return ostr << osstr.str();
}

}
