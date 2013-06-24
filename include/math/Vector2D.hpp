/** 
 * @file  include/math/Vector2D.hpp
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
 *  @brief 2D vector
 *  @ingroup math
 *  @param  Tp  type of element
 */
template<class Tp>
struct Point2D;

template< class Tp >
struct Vector2D {
	typedef Tp ValType;
	typedef ValType value_type;
	typedef Vector2D<ValType> SelfType;
	typedef SelfType const   CSelfType;
	typedef SelfType  &      SelfRefType;
	typedef CSelfType &      CSelfRefType;
	
	ValType x, y;

	/*
	 *  constructor
	 */
	BR_CONSTEXPR Vector2D( void ) : x(), y() { }

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR explicit Vector2D( Vector2D< Up > const & src )
		: x( src.x ), y( src.y ) { }

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR explicit Vector2D( Point2D< Up > const & src )
		: x( src.x ), y( src.y ) { }

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR explicit Vector2D( Point2D< Up > const & from, Point2D< Vp > const & to )
		: x( from.x - to.x ), y( from.y - to.y ) { }

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR Vector2D( Up const & xx, Vp const & yy )
		: x( xx ), y( yy ) { }
	/*
	 *  assignment
	 */
	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	SelfRefType assign( Vector2D< Up > const & src ) {
		x = src.x;
		y = src.y;
		return *this;
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	SelfRefType assign( Point2D< Up > const & src ) {
		x = src.x;
		y = src.y;
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
	BR_CONSTEXPR SelfType add( Vector2D< Up > const & rhs ) const { 
		return SelfType( x + rhs.x, y + rhs.y );
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR SelfType sub( Vector2D< Up > const & rhs ) const { 
		return SelfType( x - rhs.x, y - rhs.y );
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR SelfType add( Up const & rhsx, Vp const & rhsy ) const {
		return SelfType( x + rhsx, y + rhsy );
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR SelfType sub( Up const & rhsx, Vp const & rhsy ) const {
		return SelfType( x - rhsx, y - rhsy );
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR SelfType mul( Up const & rhs ) const {
		return SelfType( x * rhs, y * rhs );
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR SelfType div( Up const & rhs ) const {
		return SelfType( x / rhs, y / rhs );
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR SelfType add_all( Up const & rhs ) const {
		return SelfType( x + rhs, y + rhs );
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR SelfType sub_all( Up const & rhs ) const {
		return SelfType( x - rhs, y - rhs );
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
	SelfRefType self_mul( Up const & rhs ) const {
		x *= rhs;
		y *= rhs;
		return *this;
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	SelfRefType self_div( Up const & rhs ) const {
		x /= rhs;
		y /= rhs;
		return *this;
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	SelfRefType self_add_all( Up const & rhs ) const {
		x += rhs;
		y += rhs;
		return *this;
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	SelfRefType self_sub_all( Up const & rhs ) const {
		x -= rhs;
		y -= rhs;
		return *this;
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR ValType inner_product( Vector2D< Up > const & rhs ) const {
		return x * rhs.x + y * rhs.y;
	}

	template< class Up >
	BR_CONSTEXPR ValType dot_product( Vector2D< Up > const & rhs ) const {
		return inner_product( rhs );
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR ValType outer_product( Vector2D< Up > const & rhs ) const {
		return x * rhs.y - y * rhs.x;
	}

	template< class Up >
	BR_CONSTEXPR ValType cross_product( Vector2D< Up > const & rhs ) const {
		return outer_product( rhs );
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR bool eql( Vector2D< Up > const & rhs ) const {
		return x == rhs.x && y == rhs.y;
	}

	template< class Up BR_ENABLE_CONVERTIBLE_ONE( ValType, Up ) >
	BR_CONSTEXPR bool neq( Vector2D< Up > const & rhs ) const {
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

	BR_CONSTEXPR SelfRefType pos( void ) {
		return *this;
	}

	BR_CONSTEXPR CSelfRefType pos( void ) const {
		return *this;
	}

	BR_CONSTEXPR SelfType neg( void ) const {
		return SelfType( -x, -y );
	}

	BR_CONSTEXPR ValType magnitude_sqr( void ) const {
		return x * x + y * y;
	}

	BR_CONSTEXPR ValType norm_sqr( void ) const {
		return magnitude_sqr();
	}

	BR_CONSTEXPR ValType length_sqr( void ) const {
		return magnitude_sqr();
	}

	BR_CONSTEXPR ValType magnitude( void ) const {
		return std::sqrt( magnitude() );
	}

	BR_CONSTEXPR ValType norm( void ) const {
		return magnitude();
	}

	BR_CONSTEXPR ValType length( void ) const {
		return magnitude();
	}

	SelfRefType unitize( void ) {
		ValType len = magnitude();
		x /= len;
		y /= len;
		return *this;
	}

	BR_CONSTEXPR SelfRefType normalize( void ) {
		return unitize();
	}

	SelfType unit() const { 
		ValType len = magnitude();
		return SelfType( x / len, y / len );
	}

	BR_CONSTEXPR ValType arg() const {
		return std::atan2(y, x);
	}

	BR_CONSTEXPR ValType tan_arg() const {
		return y / x;
	}

	template< class Up, class Vp BR_ENABLE_CONVERTIBLE_TWO( ValType, Up, Vp ) >
	BR_CONSTEXPR SelfRefType rotate( Up const & val_sin, Vp const & val_cos ) {
		return assign( x * val_cos - y * val_sin, x * val_sin + y * val_cos );
	}

	template< class Up >
	BR_CONSTEXPR SelfRefType rotate( Up const & angle ) {
		return rotate( std::sin( angle ), std::cos( angle ) );
	}
	/*
	 *  operator
	 */
	template< class Up >
	BR_CONSTEXPR SelfRefType operator=( Vector2D< Up > const & src ) {
		return assign( src );
	}

	BR_CONSTEXPR SelfRefType operator+() {
		return *this;
	}

	BR_CONSTEXPR CSelfRefType operator+() const {
		return *this;
	}

	BR_CONSTEXPR SelfType operator-() const {
		return SelfType( -x, -y );
	}
};

template< class Tp, class Up, class Vp >
BR_CONSTEXPR inline Vector2D< Tp > rotate(
	Vector2D< Tp > const & vec,
	Up const & sin_val,
	Vp const & cos_val
) {
	return vec.rotate( sin_val, cos_val );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Vector2D< Tp > rotate(
	Vector2D< Tp > const & vec,
	Up const & angle
) {
	return vec.rotate( angle );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Tp cos(
	Vector2D< Tp > const & lhs,
	Vector2D< Up > const & rhs
) {
	return lhs.inner_prod( rhs ) / sqrt( lhs.magnitude() * rhs.magnitude() );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Tp angle(
	Vector2D< Tp > const & lhs,
	Vector2D< Up > const & rhs
) {
	return acos( cos( lhs, rhs ) );
}
	
template< class Tp, class Up >
BR_CONSTEXPR inline Vector2D< Tp > operator+(
	Vector2D< Tp > const & lhs,
	Vector2D< Up > const & rhs
) {
	return lhs.add( rhs );
}
	
template<class Tp, class Up>
BR_CONSTEXPR inline Vector2D<Tp> operator-(
	Vector2D< Tp > const & lhs,
	Vector2D< Up > const & rhs
) {
	return lhs.sub( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Vector2D< Tp > operator*(
	Tp const & lhs,
	Vector2D< Up > const & rhs
) {
	return rhs.mul( lhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Vector2D< Tp > operator*(
	Vector2D< Tp > const & lhs,
	Up const & rhs
) {
	return lhs.mul( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Vector2D< Tp > operator/(
	Vector2D< Tp > const & lhs,
	Up const & rhs
) {
	return lhs.div( rhs );
}
	
template< class Tp, class Up >
BR_CONSTEXPR inline Vector2D< Tp > & operator+=(
	Vector2D< Tp > & lhs,
	Vector2D< Up > const & rhs
) {
	return lhs.self_add( rhs );
}
	
template< class Tp, class Up >
BR_CONSTEXPR inline Vector2D<Tp> & operator-=(
	Vector2D< Tp > & lhs,
	Vector2D< Up > const & rhs
) {
	return lhs.self_sub( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Vector2D< Tp > & operator*=(
	Vector2D< Tp > & lhs,
	Up const & rhs
)  {
	return lhs.self_mul( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Vector2D< Tp > & operator/=(
	Vector2D< Tp > & lhs,
	Up const & rhs
)  {
	return lhs.self_div( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline bool operator==(
	Vector2D< Tp > const & lhs,
	Vector2D< Up > const & rhs
) {
	return lhs.eql( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline bool operator!=(
	Vector2D< Tp > const & lhs,
	Vector2D< Up > const & rhs
) {
	return lhs.neq( rhs );
}

template< class ValType, class CharType, class CharTraits >
std::basic_istream< CharType, CharTraits > & operator>>(
	std::basic_istream< CharType, CharTraits > & istr,
	Vector2D< ValType > & vec)
{
	ValType vecx, vecy;
	CharType ch;
	istr >> ch;
	if ( ch == '(' ) {
		istr >> vecx >> ch;
		if ( ch == ',' ) {
			istr >> vecy >> ch;
			if ( ch == ')' ) {
				vec = Vector2D< ValType >( vecx, vecy );
			} else {
				istr.setstate( std::ios_base::failbit );
			}
		} else if ( ch == ')' ) {
			vec = Vector2D< ValType >( vecx, ValType() );
		} else {
			istr.setstate( std::ios_base::failbit );
		}
	} else {
		istr >> vecx;
		vec = Vector2D< ValType >( vecx, ValType() );
	}
	return istr;
}

template< class ValType, class CharType, class CharTraits >
std::basic_ostream< CharType, CharTraits >& operator<<(
	std::basic_ostream< CharType, CharTraits > & ostr,
	Vector2D< ValType > const & rhs)
{
	std::basic_ostringstream< CharType, CharTraits > osstr;
	osstr.flags( ostr.flags() );
	osstr.imbue( ostr.getloc() );
	osstr.precision( ostr.precision() );
	osstr << '(' << rhs.x << ',' << rhs.y << ')';
	return ostr << osstr.str();
}

}
