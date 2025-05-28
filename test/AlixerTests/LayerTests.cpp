#include "pch.h"

#include "Core/Layer.h"

namespace AlixerTests
{
	using namespace Alixer;
	using namespace Microsoft::VisualStudio::CppUnitTestFramework;

	TEST_CLASS(LayerTests)
	{
	public:
		TEST_METHOD(Success_CreateLayer)
		{
			const Layer layer("Test Layer");
			Assert::IsFalse(layer.IsEmpty(), L"Layer should not be empty");
			Assert::AreEqual("Test Layer", layer.GetName(), L"Layer name is incorrect");
			Assert::IsTrue(layer.GetId() != Uuid::Empty(), L"Layer ID should not be empty");
		}

		TEST_METHOD(Success_CopyConstructor)
		{
			const Layer originalLayer("Original Layer");
			const Layer copiedLayer(originalLayer);  // NOLINT(performance-unnecessary-copy-initialization)
			Assert::IsFalse(copiedLayer.IsEmpty(), L"Copied layer should not be empty");
			Assert::AreEqual(originalLayer.GetName(), copiedLayer.GetName(), L"Copied layer name is incorrect");
			Assert::IsTrue(copiedLayer.GetId() == originalLayer.GetId(), L"Copied layer ID should match original");
		}

		TEST_METHOD(Success_MoveConstructor)
		{
			const Layer originalLayer("Original Layer");
			const Uuid id = originalLayer.GetId();  // NOLINT(performance-unnecessary-copy-initialization)
			const Layer movedLayer(std::move(originalLayer));  // NOLINT(performance-move-const-arg)
			Assert::IsFalse(movedLayer.IsEmpty(), L"Moved layer should not be empty");
			Assert::AreEqual("Original Layer", movedLayer.GetName(), L"Moved layer name is incorrect");
			Assert::IsTrue(movedLayer.GetId() == id, L"Moved layer ID should match original");
		}

		TEST_METHOD(Success_EqualityOperator)
		{
			const Layer layer1("Layer 1");
			const Layer layer2("Layer 2");
			const Layer layer3 = layer1;  // NOLINT(performance-unnecessary-copy-initialization)
			Assert::IsTrue(layer1 == layer3, L"Layers with the same name and ID should be equal");
			Assert::IsFalse(layer1 == layer2, L"Layers with different names or IDs should not be equal");
		}

		TEST_METHOD(Success_InequalityOperator)
		{
			const Layer layer1("Layer 1");
			const Layer layer2("Layer 2");
			Assert::IsTrue(layer1 != layer2, L"Layers with different names or IDs should be unequal");
		}

		TEST_METHOD(Success_GetName)
		{
			const Layer layer("Test Layer");
			Assert::AreEqual("Test Layer", layer.GetName(), L"GetName should return the correct layer name");
		}

		TEST_METHOD(Success_GetId)
		{
			const Layer layer("Test Layer");
			Assert::IsTrue(layer.GetId() != Uuid::Empty(), L"GetId should return a non-empty UUID");
		}

		TEST_METHOD(Success_IsEmpty)
		{
			const Layer emptyLayer(Layer::Empty());
			Assert::IsTrue(emptyLayer.IsEmpty(), L"Empty layer should be recognized as empty");

			Assert::IsTrue(emptyLayer.GetId() == Uuid::Empty(), L"Empty layer ID should be equal to Uuid::Empty()");
			Assert::AreEqual(Layer::Empty().GetName(), emptyLayer.GetName(), L"Empty layer name should match Layer::Empty() name");

			const Layer nonEmptyLayer("Non-Empty Layer");
			Assert::IsFalse(nonEmptyLayer.IsEmpty(), L"Non-empty layer should not be recognized as empty");
		}
	};
}
