#pragma once
enum class TileState
{
    Hidden = 0,
    Revealed = 1,
    Marked = 2
};

enum class TileType
{
    Empty = 0,
    Bomb = 1,
    Count = 2
};

class Tile
{
private:
    // Variables
    TileState m_state;
    TileType m_type;

    int m_adjacentBombCount;

    //Functions
    void DisplayRevealed();
public:
    // Constructor and destructor
    Tile();
    virtual ~Tile();
    TileType getTileType();
    void setTileType(TileType);
    TileState getTileState();
    void setTileState(TileState tileState);
    bool checkTileType(TileType type);
    bool isBomb();
    bool isEmpty();
    void print();
};

