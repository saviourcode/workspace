#include <iostream>
#include <cstdio>
#include <cstring>

class HashTable
{
public:
    HashTable(size_t tableSize) : tableSize_(tableSize), table_(new char *[tableSize]
                                                                { NULL }),
                                  numEntries(0), collisions(0){};
    bool isEmpty() const;
    void insertItem(char *);
    size_t collisions;

private:
    size_t tableSize_;
    char **table_;
    size_t numEntries;

    unsigned int hashFunction(char *);
    size_t isPrime(size_t);
};

unsigned int HashTable::hashFunction(char *s)
{
    char c{};
    unsigned int hash{};

    while ((c = *s++))
        hash += c;

    return hash;
}

size_t HashTable::isPrime(size_t tmp)
{
    for (size_t i = 2; i * i <= tmp; i++)
    {
        if (tmp % i == 0)
        {
            return isPrime(--tmp);
        }
    }
    return tmp;
}

void HashTable::insertItem(char *s)
{
    unsigned int key = hashFunction(s);
    unsigned int probe = 0;
    unsigned int loc = (key + probe * probe) % tableSize_;

    if (numEntries < tableSize_ / 2)
    {
        while (table_[loc] != NULL)
        {
            probe++;
            loc = (key + probe * probe) % tableSize_;
            collisions++;
        }
        size_t len = strlen(s) + 1;
        table_[loc] = new char[len];

        memcpy(table_[loc], s, len);
    }
    else
    {
        printf("\nCollisions in this table %02d\n", collisions);
        collisions = 0;
        size_t tempTableSize = isPrime(tableSize_ * 2);
        char **tempTable = new char *[tempTableSize];
        printf("Increasing Table Size from %02d to %02d and rehasing ...\n", tableSize_, tempTableSize);

        printf("\n-------------------------------->\n");
        for (size_t i = 0; i < tableSize_; i++)
        {
            if (table_[i] != NULL)
            {
                key = hashFunction(table_[i]);
                probe = 0;
                loc = (key + probe * probe) % tempTableSize;

                while (tempTable[loc] != NULL)
                {
                    probe++;
                    loc = (key + probe * probe) % tempTableSize;
                    collisions++;
                }
                size_t len = strlen(table_[i]) + 1;
                tempTable[loc] = new char[len];

                memcpy(tempTable[loc], table_[i], len);

                delete table_[i];
                printf("[/] Entry: %02d hash: %02d index: %02d Value: %s\n", numEntries, key % tempTableSize, loc, tempTable[loc]);
            }
        }
        printf("<--------------------------------\n\n");

        delete[] table_;

        key = hashFunction(s);
        probe = 0;
        loc = (key + probe * probe) % tempTableSize;

        while (tempTable[loc] != NULL)
        {
            probe++;
            loc = (key + probe * probe) % tempTableSize;
            collisions++;
        }
        size_t len = strlen(s) + 1;
        tempTable[loc] = new char[len];

        memcpy(tempTable[loc], s, len);

        tableSize_ = tempTableSize;
        table_ = tempTable;

        delete[] tempTable;
    }

    numEntries++;

    printf("[+] Entry: %02d hash: %02d index: %02d Value: %s\n", numEntries, key % tableSize_, loc, table_[loc]);
}

void removeNL(char *s)
{
    size_t len = strlen(s) - 1;
    s += len;
    *s = '\0';
}

int main()
{
    FILE *input;
    char buffer[10];

    input = fopen("input", "r");

    if (input == NULL)
        perror("Error Opening Input File");

    else
    {
        HashTable ht(31);
        while (!feof(input))
        {
            // read from the file
            if (fgets(buffer, 10, input) == NULL)
                break;
            removeNL(buffer);

            ht.insertItem(buffer);
        }
        fclose(input);
        printf("\nCollisions in this table %02d",ht.collisions);
    }

    return 0;
}