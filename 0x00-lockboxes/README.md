# Algorithm
- Initialize `keys` list with the element of the first list
- Create a dictionary `d` with keys from 0 to length(boxes) - 1
- Initialize `d[0]` with `unlocked` and the rest with `locked`
- Loop through the boxes and check if index is in the list keys
- If the index is in the keys list extract numbers from the list and add them to key ( do not add duplicate or 0 or None)
- Check every locked key in `d` if it exists in keys list `unlock` it and add the key to the `keys` list then repeat this process
- return `True` if `unlocked` doesn't exists in `d.values()`