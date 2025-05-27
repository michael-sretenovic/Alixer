#include "pch.h"

#include "Core/Uuid.h"

namespace AlixerTests
{
	using namespace Alixer;
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(UuidTests)
	{
	public:
		TEST_METHOD(Success_CreateUuid)
		{
			const Uuid uuid;
			Assert::IsTrue(uuid != 0, L"UUID value should not be zero");
		}

		TEST_METHOD(Success_ImplicitCastToUint64)
		{
			constexpr uint64_t value = 123456789;
			const Uuid uuid(value);
			const uint64_t uuidValue = uuid;  // Implicit cast to uint64_t
			Assert::AreEqual(value, uuidValue, L"Implicit cast to uint64_t should match the UUID value");
		}

		TEST_METHOD(Success_EqualityOperator)
		{
			constexpr uint64_t value = 123456789;
			const Uuid uuid1(value);
			const Uuid uuid2(value);
			Assert::IsTrue(uuid1 == uuid2, L"UUIDs with the same value should be equal");
		}

		TEST_METHOD(Success_InequalityOperator)
		{
			constexpr uint64_t value1 = 123456789;
			constexpr uint64_t value2 = 987654321;
			const Uuid uuid1(value1);
			const Uuid uuid2(value2);
			Assert::IsTrue(uuid1 != uuid2, L"UUIDs with different values should not be equal");
		}

		TEST_METHOD(Success_CreateUuidWithValue)
		{
			constexpr uint64_t value = 123456789;
			const Uuid uuid(value);
			Assert::IsTrue(uuid == value, L"UUID should match the provided value");
		}

		TEST_METHOD(Success_CopyConstructor)
		{
			const Uuid originalUuid;
			const Uuid copiedUuid(originalUuid);  // NOLINT(performance-unnecessary-copy-initialization)
			Assert::IsTrue(copiedUuid == originalUuid, L"Copied UUID should match the original UUID");
		}

		TEST_METHOD(Success_MoveConstructor)
		{
			constexpr uint64_t value = 123456789;
			const Uuid originalUuid(value);
			const Uuid movedUuid(std::move(originalUuid));  // NOLINT(performance-move-const-arg)
			Assert::IsTrue(movedUuid == value, L"Moved UUID should match the original UUID");
		}

		TEST_METHOD(Success_CopyOperator)
		{
			const Uuid originalUuid;
			const Uuid copiedUuid = originalUuid;  // NOLINT(performance-unnecessary-copy-initialization)
			Assert::IsTrue(copiedUuid == originalUuid, L"Copied UUID should match the original UUID");
		}

		TEST_METHOD(Success_MoveOperator)
		{
			constexpr uint64_t value = 123456789;
			Uuid originalUuid(value);
			const Uuid movedUuid = std::move(originalUuid);  // NOLINT(performance-move-const-arg)
			Assert::IsTrue(movedUuid == value, L"Moved UUID should match the original UUID");
		}

		TEST_METHOD(Success_HashIsStable)
		{
			constexpr uint64_t value = 123456789;
			const Uuid uuid(value);
			const size_t hash1 = uuid.Hash();
			const size_t hash2 = uuid.Hash();
			Assert::AreEqual(hash1, hash2, L"Hash should be stable for the same UUID");
		}

		TEST_METHOD(Success_Generate)
		{
			const Uuid uuid1 = Uuid::Generate();
			const Uuid uuid2 = Uuid::Generate();
			Assert::IsTrue(uuid1 != uuid2, L"Generated UUIDs should be different");
			Assert::IsTrue(uuid1 != 0, L"Generated UUID should not be zero");
			Assert::IsTrue(uuid2 != 0, L"Generated UUID should not be zero");
		}

		TEST_METHOD(Success_EmptyUuid)
		{
			const Uuid emptyUuid = Uuid::Empty();
			Assert::IsTrue(emptyUuid == 0, L"Empty UUID should be equal to zero");
		}
	};
}
