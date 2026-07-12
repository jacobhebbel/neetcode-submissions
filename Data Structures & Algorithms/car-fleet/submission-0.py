class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        
        # each car starts at mile position[i] with constant speed speed[i]
        # cars can not pass each other: if i starts before j, it goes j's speed or slower
        
        # idea: map position to car, then sort position (nlogn runtime)
        # maybe we could use a priority queue? 

        # tracks car-mile relationship after sort
        # allowed bc pos's are unique
        mile_to_car = {
            mile: car 
            for car, mile in enumerate(position)
        }

        # use sorted miles to group fleets (furthest slower fleet dictates)
        slowest_time = float('inf')
        longest_ttd, num_fleets = 0, 0
        sorted_miles = sorted(position, reverse=True)

        for m in sorted_miles:

            car = mile_to_car[m]
            ttd = (target - m) / speed[car]
            print(f'car {car} has ttd {ttd}')

            if ttd > longest_ttd:
                print(f'car {car} is in a new fleet')
                num_fleets+=1
            
            longest_ttd = max(ttd, longest_ttd)

        return num_fleets


