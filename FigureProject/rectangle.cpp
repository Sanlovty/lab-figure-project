#include "rectangle.h"

Rectangle::Rectangle() :
	leftTop_(point_t()),
	rightTop_(point_t()),
	rightBottom_(point_t()),
	leftBottom_(point_t())
{
}

Rectangle::Rectangle(const double& leftTopX,
                     const double& leftTopY,
                     const double& rightTopX,
                     const double& rightTopY,
                     const double& rightBottomX,
                     const double& rightBottomY,
                     const double& leftBottomX,
                     const double& leftBottomY) :
	leftTop_(point_t(leftTopX, leftTopY)),
	rightTop_(point_t(rightTopX, rightTopY)),
	rightBottom_(point_t(rightBottomX, rightBottomY)),
	leftBottom_(point_t(leftBottomX, leftBottomY))
{
}

Rectangle::Rectangle(const point_t& leftTop,
                     const point_t& rightTop,
                     const point_t& rightBottom,
                     const point_t& leftBottom) :
	leftTop_(leftTop),
	rightTop_(rightTop),
	rightBottom_(rightBottom),
	leftBottom_(leftBottom)
{
}

void Rectangle::rotate(const double& angle)
{
	const point_t center = getCenter();
	leftTop_ = rotatePoint_(leftTop_, center, angle);
	rightTop_ = rotatePoint_(rightTop_, center, angle);
	rightBottom_ = rotatePoint_(rightBottom_, center, angle);
	leftBottom_ = rotatePoint_(leftBottom_, center, angle);
}

void Rectangle::move(const double& x, const double& y)
{
	leftTop_ = movePoint_(leftTop_, x, y);
	rightTop_ = movePoint_(rightTop_, x, y);
	rightBottom_ = movePoint_(rightBottom_, x, y);
	leftBottom_ = movePoint_(leftBottom_, x, y);
}

void Rectangle::resize(const double& multiplier)
{
	if (multiplier == 0.0)
	{
		throw exception("Multiplier must be not null");
	}
}

void Rectangle::setHeight(const double& height)
{
	if (height <= 0)
	{
		throw exception("height must be positive number");
	}
	leftTop_.second = rightTop_.second = leftBottom_.second + height;
}

void Rectangle::setWidth(const double& width)
{
	if (width <= 0)
	{
		throw exception("height must be positive number");
	}
	rightBottom_.first = rightTop_.first = leftBottom_.first + width;
}

double Rectangle::getHeight() const
{
	return abs(leftTop_.first - leftBottom_.first);
}

double Rectangle::getWidth() const
{
	return abs(leftTop_.second - rightTop_.second);
}

point_t Rectangle::getCenter() const
{
	return point_t((leftTop_.first + rightTop_.first) / 2, (leftTop_.second + leftBottom_.second) / 2);
}