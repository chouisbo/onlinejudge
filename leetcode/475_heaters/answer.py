import bisect

class Solution(object):
    def findRadius(self, houses, heaters):
        """
        :type houses: List[int]
        :type heaters: List[int]
        :rtype: int
        """
        radious, n, heaters = 0, len(heaters), sorted(heaters)
        for house in houses:
            distance, i = 0, bisect.bisect_left(heaters, house)
            if i == 0: distance = heaters[0] - house
            elif i == n: distance = house - heaters[-1]
            else: distance = min(house - heaters[i-1], heaters[i] - house)
            if radious < distance: radious = distance
        return radious
