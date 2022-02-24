// HomeWork220224DeleteMap.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <crtdbg.h>

using DataType = int;
using KeyType = int;

struct GamePair
{
    KeyType first;
    DataType second;
};

GamePair make_gamePair(const KeyType& _Key, const DataType& _Data)
{
    return GamePair{ _Key, _Data };
}

enum class MapNodeType
{
    Root,
    LeftChild,
    RightChild,
    Error,
};

class GameMap
{
private:
    class MapNode
    {
    public:
        GamePair Pair_;
        MapNodeType Type;
        // 0 루트
        // 1 레프트 차일드
        // 2 라이트 차일드
        // 3 MAX 에러

        MapNode* Parent_;
        MapNode* LeftChild_;
        MapNode* RightChild_;

    public:
        void DeleteOrder()
        {   
            MapNode* Node = this;
            MapNode* NextNode = nullptr;
            while (nullptr != Node)
            {
                if (nullptr != Node->RightChild_)
                {
                    Node = Node->RightChild_;
                }
                else if (nullptr != Node->LeftChild_)
                {
                    Node = Node->LeftChild_;
                }
                if (nullptr == Node->RightChild_ && nullptr == Node->LeftChild_)
                {
                    Node = NodeDelete(Node);
                }
            }
        }

        MapNode* NodeDelete(MapNode* Node_)
        {
			MapNode* NextNode = nullptr;
			if (Node_->Type == MapNodeType::LeftChild)
			{
				Node_->Parent_->LeftChild_ = nullptr;
			}
			if (Node_->Type == MapNodeType::RightChild)
			{
				Node_->Parent_->RightChild_ = nullptr;
			}
			NextNode = Node_->Parent_;
			if (Node_ != nullptr)
			{
				delete Node_;
			}
            return NextNode;
		}
        void FirstOrder()
        {
            // 내가 해야할일
            std::cout << Pair_.first << std::endl;
            if (nullptr != LeftChild_)
            {
                LeftChild_->FirstOrder();
            }
            if (nullptr != RightChild_)
            {
                RightChild_->FirstOrder();
            }
        }

        void MidOrder()
        {
            if (nullptr != LeftChild_)
            {
                LeftChild_->MidOrder();
            }
            std::cout << Pair_.first << std::endl;
            if (nullptr != RightChild_)
            {
                RightChild_->MidOrder();
            }
        }

        void LastOrder()
        {
            if (nullptr != LeftChild_)
            {
                LeftChild_->LastOrder();
            }
            if (nullptr != RightChild_)
            {
                RightChild_->LastOrder();
            }
            std::cout << Pair_.first << std::endl;
        }

        // 나보다 큰 부모를 찾는 함수
        MapNode* OverParent(const KeyType& _Key)
        {
            if (nullptr == Parent_)
            {
                return nullptr;
            }

            if (Parent_->Pair_.first < _Key)
            {
                return Parent_->OverParent(_Key);
            }

            return Parent_;
        }

        MapNode* NextNode()
        {
            if (nullptr != RightChild_)
            {
                return RightChild_->MinNode();
            }

            return OverParent(Pair_.first);
        }

        MapNode* MinNode()
        {
            if (nullptr == LeftChild_)
            {
                return this;
            }

            return LeftChild_->MinNode();
        }

        MapNode* MaxNode()
        {
            if (nullptr == RightChild_)
            {
                return this;
            }

            return RightChild_->MaxNode();
        }

        MapNode* Find(const KeyType& _Key)
        {

            if (Pair_.first == _Key)
            {
                return this;
            }

            if (Pair_.first > _Key)
            {
                if (nullptr == LeftChild_)
                {
                    return nullptr;
                }

                return LeftChild_->Find(_Key);
            }

            if (Pair_.first < _Key)
            {
                if (nullptr == RightChild_)
                {
                    return nullptr;
                }

                return RightChild_->Find(_Key);
            }

            return nullptr;
        }

        bool Insert(const GamePair& _Pair)
        {
            GamePair ThisPair = Pair_;

            if (Pair_.first > _Pair.first)
            {
                if (nullptr == LeftChild_)
                {
                    LeftChild_ = new MapNode();
                    LeftChild_->Pair_ = _Pair;
                    LeftChild_->Parent_ = this;
                    LeftChild_->Type = MapNodeType::LeftChild;
                    return true;
                }

                return LeftChild_->Insert(_Pair);
            }

            else if (Pair_.first < _Pair.first)
            {
                if (nullptr == RightChild_)
                {
                    RightChild_ = new MapNode();
                    RightChild_->Pair_ = _Pair;
                    RightChild_->Parent_ = this;
                    RightChild_->Type = MapNodeType::RightChild;
                    return true;
                }

                return RightChild_->Insert(_Pair);
            }

            return false;
        }

        MapNode()
            : Parent_(nullptr)
            , LeftChild_(nullptr)
            , RightChild_(nullptr)
            , Type(MapNodeType::Error)
        {
        }
    };

    public:
        class iterator
        {
        private:
            MapNode* Node_;

        public:
            GamePair* operator->()
            {
                return &(Node_->Pair_);
            }

            bool operator!=(const iterator& _Other)
            {
                return Node_ != _Other.Node_;
            }

            bool operator==(const iterator& _Other)
            {
                return Node_ == _Other.Node_;
            }

            iterator& operator++()
            {
                Node_ = Node_->NextNode();
                return *this;
            }

        public:
            iterator(MapNode* _Node)
                : Node_(_Node)
            {
            }

            iterator()
                : Node_(nullptr)
            {
            }

        };

        public:
            // 시발점이 되는 노드
            MapNode* RootNode_;

            bool insert(const GamePair& _Pair)
            {
                // 체크할수밖에없습니다.
                if (nullptr == RootNode_)
                {
                    RootNode_ = new MapNode();
                    RootNode_->Type = MapNodeType::Root;
                    RootNode_->Pair_ = _Pair;
                    return true;
                }

                return RootNode_->Insert(_Pair);
            }

            iterator Find(const KeyType& _Key)
            {
                return GameMap::iterator(RootNode_->Find(_Key));
            }

            iterator begin()
            {
                return GameMap::iterator(RootNode_->MinNode());
            }

            iterator end()
            {
                return GameMap::iterator(nullptr);
            }
            void Release()
            {
                RootNode_->DeleteOrder();
            }

            void FirstOrder()
            {
                RootNode_->FirstOrder();
            }
            void MidOrder()
            {
                RootNode_->MidOrder();
            }
            
            void LastOrder()
            {
                RootNode_->LastOrder();
            }

     

      public:
          GameMap()
              : RootNode_(nullptr)
          {
          }

          ~GameMap()
          {
              Release();
          }

};

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    GameMap GMap;

    GMap.insert(make_gamePair(10, 10));
    GMap.insert(make_gamePair(5, 10));
    GMap.insert(make_gamePair(7, 10));
    GMap.insert(make_gamePair(1, 10));
    GMap.insert(make_gamePair(20, 10));
    GMap.insert(make_gamePair(25, 10));
    GMap.insert(make_gamePair(17, 10));


    std::cout << "이터레이터 순회" << std::endl;
    GameMap::iterator beginIter = GMap.begin();
    GameMap::iterator endIter = GMap.end();

    for (; beginIter != endIter; ++beginIter)
    {
        std::cout << beginIter->first << std::endl;
    }
}

