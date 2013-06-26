/** 
 * @file  include/math/Vector2D.hpp
 */
#pragma once

#include <config.hpp>

#include <cmath>
#include <ios>
#include <sstream>
#include HEADER_TYPE_TRAITS
#include <tuple>

#include <math/XYPair.hpp>

namespace BR {
template< class Tp >
struct Point2D;
/**
 *  @brief 2D vector
 *  @ingroup math
 *  @param  Tp  type of element
 */
template< class Tp >
struct Vector2D : XYPair< Tp > {
	BR_VALTYPE_SERIES( Tp )
	BR_SELFTYPE_SERIES( Vector2D<ValType> )
	typedef XYPair<ValType>    SuperType;

	typedef ValType value_type;
	/*
	 *  constructor
	 */
	BR_CONSTEXPR Vector2D( void ) : SuperType() { }

	template< class Up >
	BR_CONSTEXPR Vector2D( XYPair< Up > const & src ) : SuperType( src ) { }

	template<class Up, class Vp >
	BR_CONSTEXPR Vector2D( Up const & xx, Vp const & yy ) : SuperType( xx, yy ) { }

	template< class Up, class Vp >
	BR_CONSTEXPR explicit Vector2D( Point2D< Up > const & from, Point2D< Vp > const & to )
		: SuperType( from.x - to.x , from.y - to.y ) { }

	/*
	 *  operation
	 */
	template< class Up >
	BR_CONSTEXPR SelfType add( Vector2D< Up > const & rhs ) const { 
		return SelfType( x + rhs.x, y + rhs.y );
	}

	template< class Up >
	BR_CONSTEXPR SelfType sub( Vector2D< Up > const & rhs ) const { 
		return SelfType( x - rhs.x, y - rhs.y );
	}

	template< class Up, class Vp >
	BR_CONSTEXPR SelfType add( Up const & rhsx, Vp const & rhsy ) const {
		return SelfType( x + rhsx, y + rhsy );
	}

	template< class Up, class Vp >
	BR_CONSTEXPR SelfType sub( Up const & rhsx, Vp const & rhsy ) const {
		return SelfType( x - rhsx, y - rhsy );
	}

	template< class Up >
	BR_CONSTEXPR SelfType mul( Up const & rhs ) const {
		return SelfType( x * rhs, y * rhs );
	}

	template< class Up >
	BR_CONSTEXPR SelfType div( Up const & rhs ) const {
		return SelfType( x / rhs, y / rhs );
	}

	template< class Up >
	BR_CONSTEXPR SelfType add( Up const & rhs ) const {
		return SelfType( x + rhs, y + rhs );
	}

	template< class Up >
	BR_CONSTEXPR SelfType sub( Up const & rhs ) const {
		return SelfType( x - rhs, y - rhs );
	}

	template< class Up >
	BR_CONSTEXPR ValType inner_product( Vector2D< Up > const & rhs ) const {
		return x * rhs.x + y * rhs.y;
	}

	template< class Up >
	BR_CONSTEXPR ValType dot_product( Vector2D< Up > const & rhs ) const {
		return inner_product( rhs );
	}

	template< class Up >
	BR_CONSTEXPR ValType outer_product( Vector2D< Up > const & rhs ) const {
		return x * rhs.y - y * rhs.x;
	}

	template< class Up >
	BR_CONSTEXPR ValType cross_product( Vector2D< Up > const & rhs ) const {
		return outer_product( rhs );
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

	template< class Up, class Vp >
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
	BR_CONSTEXPR SelfRefType operator+( void ) {
		return *this;
	}

	BR_CONSTEXPR CSelfRefType operator+( void ) const {
		return *this;
	}

	BR_CONSTEXPR SelfType operator-( void ) const {
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
BR_CONSTEXPR inline Vector2D< Tp > operator-(
	Vector2D< Tp > const & lhs,
	Vector2D< Up > const & rhs
) {
	return lhs.sub( rhs );
}

template< class Tp, class Up >
BR_CONSTEXPR inline Vector2D< Up > operator*(
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

}
