#include "queue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue<int> q(5));
}

TEST(TQueue, throw_when_create_queue_with_negative_length)
{
	ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, can_push)
{
	TQueue<int> q(5);
	ASSERT_NO_THROW(q.Push(4));
}

TEST(TQueue, can_shift)
{
	TQueue<int> q(5);
	q.Push(4);
	q.Push(2);
	EXPECT_EQ(4, q.Change());
}

TEST(TQueue, can_not_shift_empty_queue)
{
	TQueue<int> q(5);
	ASSERT_ANY_THROW(q.Change(););
}

TEST(TQueue, shift_reduce_count)
{
	TQueue<int> q(5);
	q.Push(4);
	q.Push(2);
	auto d = q.Change();
	EXPECT_EQ(1, q.Count());
}

TEST(TQueue, push_increase_size)
{
	TQueue<int> q(5);
	q.Push(4);
	q.Push(2);
	q.Push(8);
	EXPECT_EQ(3, q.Count());
}

TEST(TQueue, can_not_push_full_queue)
{
	TQueue<int> q(5);
	q.Push(2);
	q.Push(2);
	q.Push(2);
	q.Push(2);
	q.Push(2);
	ASSERT_ANY_THROW(q.Push(2));
}

TEST(TQueue, can_fetch_right_order)
{
	TQueue<int> q(5);
	q.Push(4);
	q.Push(2);
	q.Push(8);

	EXPECT_EQ(4, q.Change());
	EXPECT_EQ(2, q.Change());
	EXPECT_EQ(8, q.Change());
}

TEST(TQueue, can_fetch_all_queue)
{
	TQueue<int> q(5);
	q.Push(4);
	q.Push(2);
	q.Push(8);

	EXPECT_EQ(4, q.Change());
	EXPECT_EQ(2, q.Change());

	q.Push(-5);
	q.Push(42);

	EXPECT_EQ(8, q.Change());
	EXPECT_EQ(-5, q.Change());

	q.Push(31);

	EXPECT_EQ(42, q.Change());
	EXPECT_EQ(31, q.Change());
}