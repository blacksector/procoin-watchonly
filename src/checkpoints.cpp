// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 ProCoin Developers

// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
            boost::assign::map_list_of
            (     0, uint256("0x2c8d7c463b572e4384d2764364d05d3cb6b74b361288219b08719daef5558d53"))
            (     1, uint256("0x4c55894ba97399eaf46a6484bc2c065c322150bd74cce3184338a84a0fffd13d"))
            (    79, uint256("0x3bed827423bd2dd7afdbb1eadbd36c76ea02fd75f0099993be774caa2ac48eaa"))
            (    3000, uint256("0x46267258d2402d35880a2b90f63da4ff9693bcf8d3ce20dbbac6947897fd6c68"))
            (    10000, uint256("0x7f566b90cccef5a09df799d6fedc5486fdb57433042c8dec8226c63caeeb238e"))
            (    25000, uint256("0x70a9ee72510922f67b6b1db56fea78ff8db2500306c6581a640cf875f430884f"))
            (    48000, uint256("0xc0bdf1264d16fd099862e87561b36019a2d3ac218335552cf35e7c72be06e93f"))
            ;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
        return mapCheckpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }
}
