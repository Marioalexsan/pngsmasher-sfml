#include <SFML/Graphics.hpp>
#include <vector>
#include <span>

struct Region
{
    int start    = 0;
    int end      = 0;
    int bitshift = 0;
    int addvalue = 0;
};

namespace pngsmasher
{

void regionalCorrupt(sf::Image& src, sf::Image& dest, const std::vector<Region>& regions)
{
    for (auto& region : regions)
    {

    }
}

void bitShift(const std::span<std::uint8_t>& input, const std::span<std::uint8_t>& output, int direction)
{
    if (input.size() != output.size())
        throw std::exception("Input and output must have the same size.");

    bool shiftRight = direction > 0;
    int  bits       = std::abs(direction);

    int byteShifts = bits / 8;
    int bitShifts  = bits % 8;

    auto from = shiftRight ? input.subspan(0, input.size() - byteShifts)
                           : input.subspan(byteShifts);
    auto to   = shiftRight ? output.subspan(byteShifts)
                           : output.subspan(0, output.size() - byteShifts);

    std::memcpy(to.data(), from.data(), to.size());

    if (bitShifts != 0)
    {
        if (shiftRight)
        {
            for (std::size_t i = output.size() - 1; i > 0; i--)
                output[i] = (output[i] >> bitShifts) | (output[i - 1] << (8 - bitShifts));

            output[0] >>= bitShifts;
        }
        else
        {
            for (std::size_t i = 0; i < output.size() - 1; i++)
                output[i] = (output[i] << bitShifts) | (output[i + 1] >> (8 - bitShifts));

            output[output.size() - 1] <<= bitShifts;
        }
    }
}

} // namespace pngsmasher