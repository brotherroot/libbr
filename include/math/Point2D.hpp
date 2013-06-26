
/** 
 * @file  include/math/Point2D.hpp
 */
#pragma once

#include <config.hpp>

#include <cmath>
#include <ios>
#include <sstream>

#include <math/XYPair.hpp>

namespace BR {
template< class Tp >
struct Vector2D;
/**
 *  @brief 2D point
 *  @ingroup math
 *  @param  Tp  type of element
 */
template< class Tp >
struct Point2D : XYPair< Tp > {
	BR_VALTYPE_SERIES( Tp )
	BR_SELFTYPE_SERIES( Point2D<ValType> )
	typedef XYPair<ValType>    SuperType;
	typedef Vector2D<ValType> VecType;

	typedef ValType value_type;
	/*
	 *  constructor
	 */
	BR_CONSTEXPR Point2D( void ) : SuperType() { }

	template< class Up >
	BR_CONSTEXPR Point2D( XYPair< Up > const & src ) : SuperType( src ) { }

	template<class Up, class Vp >
	BR_CONSTEXPR Point2D( Up const & xx, Vp const & yy ) : SuperType( xx, yy ) { }

	template< class Up, class Vp >
	BR_CONSTEXPR explicit Point2D( Point2D< Up > const & src, Vector2D< Vp > const & vec )
		: x( src.x + vec.x ), y( src.y + vec.y ) { }

	/*
	 *  assignment
	 */
	template< class Up, class Vp >
	SelfRefType assign( Point2D< Up > const & src, Vector2D< Vp > const & vec ) {
		x = src.x + vec.x;
		y = src.y + vec.y;
		return *this;
	}
	/*
	 *  operation
	 */
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
	BR_CONSTEXPR SelfRefType operator+( void ) {
		return *this;
	}

	BR_CONSTEXPR CSelfRefType operator+( void ) const {
		return *this;
	}

	BR_CONSTEXPR SelfType operator-( void ) const {
		return SelfType( -x, -y );
	}

	template< class Up, class Vp >
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

}
